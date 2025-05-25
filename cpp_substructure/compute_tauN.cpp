// compute_tauN.cpp
#include <iostream>
#include <vector>
#include <string>
#include "fastjet/PseudoJet.hh"
#include "fastjet/ClusterSequence.hh"

#include "fastjet/contrib/Nsubjettiness.hh"
#include "fastjet/contrib/AxesDefinition.hh"
#include "fastjet/contrib/MeasureDefinition.hh"

#include <fstream>
#include <sstream>
#include <cmath>

int main() {
    std::cout << "FastJet N-subjettiness computation setup starting..." << std::endl;

    // A vector of jets -> each jet is a vector of particles
    std::vector<std::vector<fastjet::PseudoJet>> jets;

    // Open the toy text file
    std::ifstream infile("jets_particles.txt");
    std::string line;
    std::vector<fastjet::PseudoJet> current_jet; // Storing the current jet being read

    // Reading line by line
    while (std::getline(infile, line)) {
        std::istringstream iss(line);
        double pt, eta, phi;
        
        if (!(iss >> pt >> eta >> phi)) {
            // Blank line indicates end of current jet
            if (!current_jet.empty()) {
                jets.push_back(current_jet);
                current_jet.clear();
            }
            continue;
        }

        // Convert (pt, eta, phi) to (px, py, pz, E), assume m = 0
        double px = pt * cos(phi);
        double py = pt * sin(phi);
        double pz = pt * sinh(eta);
        double E  = std::sqrt(px*px + py*py + pz*pz); // m = 0

        // Create a PseudoJet for each particle
        fastjet::PseudoJet particle(px, py, pz, E);
        current_jet.push_back(particle);
    }

    // Push the last jet if not empty
    if (!current_jet.empty()) {
        jets.push_back(current_jet);
    }

    std::cout << "Read " << jets.size() << " jets from file." << std::endl;

    // Creating a csv file and writing a header
    std::ofstream outfile("tau_output.csv");
    outfile << "event_id,jet_id,pt,eta,phi,tau1,tau2,tau3\n";

    // For each jet group
    for (size_t i = 0; i < jets.size(); ++i) {
        const std::vector<fastjet::PseudoJet>& particles = jets[i]; // const - do not modify this jet

        // Use anti-kT algorithm with radius R = 0.6
        fastjet::JetDefinition jet_def(fastjet::antikt_algorithm, 0.6);
        fastjet::ClusterSequence cs(particles, jet_def);
        std::vector<fastjet::PseudoJet> clustered_jets = cs.inclusive_jets();

        std::cout << "Jet group " << i << ": Found " << clustered_jets.size() << " clustered jets." << std::endl;

        // Set up axis and measure for calculating tauN
        double beta = 1.0; // Angular exponent (beta = 1 -> linear distance)
        fastjet::contrib::OnePass_KT_Axes axes_def;
        fastjet::contrib::NormalizedMeasure measure_def(beta, 0.6); 

        // Computing tau1, tau2, tau3 for each clustered jet
        for (size_t j = 0; j < clustered_jets.size(); ++j) {
            const fastjet::PseudoJet& jet = clustered_jets[j];

            fastjet::contrib::Nsubjettiness nsub1(1, axes_def, measure_def);
            fastjet::contrib::Nsubjettiness nsub2(2, axes_def, measure_def);
            fastjet::contrib::Nsubjettiness nsub3(3, axes_def, measure_def);

            double tau1 = nsub1.result(jet);
            double tau2 = nsub2.result(jet);
            double tau3 = nsub3.result(jet);

            // Printing the jet's pT, eta, phi, tau1, tau2, tau3
            std::cout << "  Jet " << j << ": pT = " << jet.pt()
                      << ", eta = " << jet.eta()
                      << ", phi = " << jet.phi()
                      << ", tau1 = " << tau1
                      << ", tau2 = " << tau2
                      << ", tau3 = " << tau3 << std::endl;

            // Saving the results to CSV
            outfile << i << "," << j << ","
                    << jet.pt() << "," << jet.eta() << "," << jet.phi() << ","
                    << tau1 << "," << tau2 << "," << tau3 << "\n";
        }
    }

    outfile.close();
    std::cout << "Computation finished." << std::endl;
    return 0;
}