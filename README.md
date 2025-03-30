# Uncertainty Quantification in CMS Jet Classification

This repository presents a complete end-to-end pipeline for distinguishing **quark** and **gluon** jets using CMS open data. It focuses on quantifying the uncertainty in deep learning predictions using **Bayesian Neural Networks (BNNs)** via **Monte Carlo Dropout**.

---

## Project Structure

The work is organized into three major phases:

### Phase 1: Hypothesis Testing
- Loaded and preprocessed jet-wise features ($p_T$, $\eta$, $\phi$)
- Engineered $p_T$-weighted jet widths (in $\eta$, $\phi$)
- Compared distributions (quark vs gluon) using:
  - Histograms
  - Cumulative Distribution Functions (CDFs)
  - Kolmogorov-Smirnov (KS) test
- Extracted insights on which features are best for discrimination

### Phase 2: Feature Engineering
- Computed jet-wise and particle-level engineered features
- Key engineered features:
  - $p_T$-weighted jet width in $\eta$ and $\phi$
  - $\Delta R$ between particles and jet centroid (mean, max)
- Quantified feature importance using:
  - Descriptive statistics (mean, std, skew, kurtosis)
  - KS statistics
  - Visual comparisons

### Phase 3: Machine Learning + Uncertainty
- Implemented and compared the following models:
  - Logistic Regression
  - Random Forest (with GridSearch)
  - Multi-Layer Perceptron (MLP)
    - 1 hidden layer (full batch)
    - 2 hidden layers (full batch)
    - 2 hidden layers (mini-batch)
  - Bayesian Neural Network (BNN via Monte Carlo Dropout)
- Used Binary Cross-Entropy Loss (BCELoss)
- Tracked loss, training curves, accuracy
- Evaluated results using:
  - Accuracy
  - Precision, Recall, F1-Score
  - Confusion Matrix

---

## Final Results (Test Set)

| Model           | Architecture     | Training Type | Accuracy | Notes                      |
|----------------|------------------|----------------|----------|----------------------------|
| Logistic Reg.  | –                | –              | ~66%     | Baseline                   |
| Random Forest  | –                | GridSearch     | **~72.65%** | Best traditional ML        |
| MLP            | 1 Hidden Layer   | Full-batch     | ~71.8%   | Stable improvement         |
| MLP            | 2 Hidden Layers  | Full-batch     | ~72.2%   | Slightly better            |
| MLP            | 2 Hidden Layers  | **Mini-batch** | **~72.34%** | Best DL model so far       |
| BNN (MC Dropout) | 2 Hidden Layers | Mini-batch     | ~72.54%  | Added uncertainty quantification |

---

## Uncertainty Quantification (MC Dropout)
- **Mean predicted probability**: per test sample
- **Uncertainty**: standard deviation of predictions over 100 stochastic passes
- **Confidence** = 1 − std

### Overall BNN Results:
- **Average Confidence**: ~92.6%
- **Average Uncertainty**: ~7.4%
- **High-confidence predictions (>90%)**: ~91.07% of test samples

---

## Usage

```bash
# 1. Clone repo
$ git clone https://github.com/yourusername/uq-cms-jets.git

# 2. Set up environment
$ pip install -r requirements.txt

# 3. Run notebooks
Phase1_Hypothesis_Testing.ipynb
Phase2_Feature_Engineering.ipynb
Phase3_Machine_Learning.ipynb
```

---

## Author
Project developed by **Saurav Bania** as part of a self-exploration on **uncertainty quantification in particle physics**.

---

## References
- Gal & Ghahramani (2016), [Dropout as a Bayesian Approximation](https://arxiv.org/abs/1506.02142)
- CMS Open Data portal
- sklearn, matplotlib, numpy, pandas, seaborn

---

#### Note
This project was conducted during Saurav Bania’s research in preparation for a PhD application focused on uncertainty quantification and interpretability in deep learning for high energy physics.

