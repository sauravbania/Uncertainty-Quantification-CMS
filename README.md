
# **Uncertainty Quantification in CMS Event Classification Using Bayesian Neural Networks**

## **📌 Project Overview**
This project explores **Uncertainty Quantification (UQ)** in **CMS event classification** using **Bayesian Neural Networks (BNNs)**. Our goal is to analyze event classification in **High Energy Physics (HEP)**, particularly in the **CMS experiment**, by applying:
- **Hypothesis Testing** (Chi-Squared Test, Likelihood Ratio Tests)
- **Maximum Likelihood Estimation (MLE)** for parameter estimation
- **Bayesian Inference** for event classification
- **Bayesian Neural Networks (BNNs)** for UQ in physics predictions

## **🔹 Motivation & Research Goals**
In experimental physics, distinguishing **signal (new physics)** from **background (Standard Model processes)** is a fundamental challenge. Standard classification methods provide **hard decisions**, but they do not quantify the **uncertainty in classification**. By introducing **Bayesian techniques**, we aim to:
✅ Improve **event classification** using probabilistic models.
✅ Quantify **uncertainty** in **signal vs. background classification**.
✅ Apply **statistical hypothesis testing** to evaluate model performance.

## **📂 Planned Workflow**
### **Phase 1: Hypothesis Testing & Statistical Foundations**
- Implement **Chi-Squared Goodness-of-Fit Test** for classification.
- Use **Likelihood Ratio Tests (LRTs)** to improve classification.
- Apply **Maximum Likelihood Estimation (MLE)** for parameter estimation.

### **Phase 2: Bayesian Inference & Uncertainty Quantification**
- Implement **Bayesian methods** to classify CMS events.
- Compare **Frequentist vs. Bayesian confidence intervals**.
- Evaluate **model uncertainty** using Bayesian techniques.

### **Phase 3: Bayesian Neural Networks for Event Classification**
- Train a **Bayesian Neural Network (BNN)** for event classification.
- Compare BNN performance with standard classification models.
- Analyze the **effect of uncertainty in physics-based decision-making**.

## **📊 Dataset Selection**
🔍 **Next Step:** Identify a relevant **CMS dataset** (real or simulated). Possible options:
- Since the project is about Uncertainty Quantification in CMS Event Classification using Bayesian Neural Networks, we need data that that contains **labeled event classifications** from **High Energy Physics (HEP)** experiments.

Characteristics of a suitable Dataset:
- Contains event-level information (features like energy, momentum, particle ID, etc.).
- Distinguishes between signal (new physics) and background (Standard Model physics).
- Is structured in a format suitable for machine learning (ROOT files, CSV, HDF5).
- Has uncertainties included (or allows us to estimate uncertainties).
- 
- Open-source **CMS experiment data**.
- Monte Carlo (MC) generated datasets.
- Simulated event classification data for proof-of-concept.

## **💻 Installation & Dependencies**
To run the statistical and ML models, install:
```bash
pip install numpy scipy matplotlib tensorflow torch pymc3
```

## **📜 Project Roadmap & Contributions**
📌 This is an evolving research project. Future extensions:
- Testing with **real CMS data**.
- Advanced Bayesian Deep Learning techniques.
- Expanding to **other HEP event classification problems**.

🚀 **Contributors**: This project is maintained by [Your Name]. Contributions are welcome!

---
📂 **Repository Structure (Initial Plan)**
```
📦 Uncertainty-Quantification-CMS
 ┣ 📜 README.md   # Project Overview
 ┣ 📜 hypothesis_testing.py  # Chi-Squared & LRT Implementation
 ┣ 📜 bayesian_inference.py  # Bayesian Classification Methods (Future Phase)
 ┣ 📜 bnn_classification.py  # Bayesian Neural Networks (Future Phase)
 ┗ 📂 datasets/  # CMS-like datasets for analysis
```

🔗 **References & Further Reading**:
- CMS Experiment: [https://cms.cern](https://cms.cern)
- Bayesian Neural Networks: [https://arxiv.org/pdf/1906.02506.pdf](https://arxiv.org/pdf/1906.02506.pdf)
- Hypothesis Testing in Physics: [https://arxiv.org/pdf/physics/0702156.pdf](https://arxiv.org/pdf/physics/0702156.pdf)

📌 **Next Steps**:
1. **Set up the GitHub repository** ✅
2. **Search & finalize a dataset** 🔍
3. **Implement Phase 1: Hypothesis Testing & Likelihood Ratios** ✏️


## Dataset
Due to Git LFS storage limits, the dataset is available for download from:
🔗 [Download `QG_jets_withbc_0.npz` here](https://zenodo.org/records/3164691)

## Processed Datasets
The processed datasets are available for download here:  
[Download Processed Data](https://drive.google.com/file/d/1tnq4J3slt3enlo-sbou0kiIOyqo1X0rn/view?usp=drive_link)

