import numpy as np

# Path to the jets_for_entropy.txt file
input_file = "jets_for_entropy.txt"

# Store entropies
entropies = []

# Temporary list to collect particles for a jet
current_jet_pts = []

# Open the file and read
with open(input_file, "r") as f:
    for line in f:
        line = line.strip()
        
        # Skip comments
        if line.startswith("#"):
            continue
        
        # Check if line is blank → end of a jet
        if not line:
            if current_jet_pts:
                total_pt = sum(current_jet_pts)
                fractions = [pt / total_pt for pt in current_jet_pts]
                entropy = -sum(f * np.log(f) for f in fractions if f > 0)
                entropies.append(entropy)
                current_jet_pts = []
            continue
        
        # Now try to parse pt, eta, phi
        try:
            pt, eta, phi = map(float, line.split())
            current_jet_pts.append(pt)
        except ValueError:
            print(f"Warning: Skipping invalid line -> {line}")
            continue

# Edge case: Last jet (if no blank at end)
if current_jet_pts:
    total_pt = sum(current_jet_pts)
    fractions = [pt / total_pt for pt in current_jet_pts]
    entropy = -sum(f * np.log(f) for f in fractions if f > 0)
    entropies.append(entropy)

# Save entropies to a CSV file
output_file = "entropy_output.csv"
np.savetxt(output_file, np.array(entropies), delimiter=",", header="entropy", comments='')

print(f"Computed entropy for {len(entropies)} jets.")
print(f"Saved entropies to {output_file}.")