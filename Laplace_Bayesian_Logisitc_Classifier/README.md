
# 🧠 Logistic Classifier with RBF Extensions
An implementation of a logistic classifier, extended with advanced features such as radial basis functions (RBFs) for non-linear decision boundaries, momentum-based parameter optimization, and Bayesian techniques for hyperparameter tuning.

---
## 📋 Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Key Functions](#key-functions)
- [Setup Instructions](#setup-instructions)
- [Implementation Details](#implementation-details)
- [Results](#results)
- [Future Work](#future-work)
- [License](#license)

  
---

## 📖 Introduction
This project demonstrates a robust implementation of a linear logistic classifier and extends it with advanced capabilities to improve classification accuracy and adaptability. It explores non-linear decision boundaries using radial basis functions, incorporates momentum for parameter optimization, and applies Bayesian principles for hyperparameter optimization. A Laplacian approximation is used to achieve a Maximum A Posteriori (MAP) solution, providing insights into a full Bayesian approach.


---

## ✨ Features

### 1. **Maximum Likelihood Estimation (MLE)**
- Fits logistic regression weights using RBF features.
- Incorporates **gradient descent with momentum** for efficient optimization.
- Includes functions for hyperparameter tuning to maximize test log-likelihood.

### 2. **Bayesian Inference with Laplace Approximation**
- Performs a Gaussian approximation of the posterior distribution for model weights.
- Visualizes weight distributions to understand uncertainty.
- Computes Bayesian predictive distributions using the posterior approximation.

### 3. **Hyperparameter Tuning**
- Optimizes learning rate (`alpha`) and RBF length scale (`l`) using grid search.
- Automatically identifies the parameters that maximize test log-likelihood.

### 4. **Visualization Tools**
- Plots training and test log-likelihoods over iterations.
- Visualizes decision boundaries and predictive distributions.
- Explores the posterior weight distributions with pairwise scatter plots.

---
## ➕ Key Functions
### **Training and Inference**
- `get_ll_test_mom`: Computes log-likelihood for test data.
- `tune_parameters_MLE`: Finds optimal learning rate and RBF length scale.
- `fit_w_mom`: Fits model weights using gradient descent with momentum.
- `compute_lpost`: Computes the log-posterior and its gradient.
- `get_MAP`: Computes the MAP solution for the posterior distribution.
- `get_S_N`: Computes the covariance matrix for the Gaussian approximation to the posterior.
### **Visualization**
- `plot_ll`: Visualizes log-likelihoods.
- `plot_predictive_distribution`: Plots decision boundaries and predictive distributions.

## ⚙️ Setup Instructions
Prerequisites
Python (>= 3.8)
NumPy
Matplotlib (for visualization)
Scikit-learn (optional, for comparison metrics)
Installation
Clone the repository:

---

## 💻 Implementation Details
### 1. **Logistic Classifier**
Implements a linear model for logistic regression with a sigmoid activation function.
### 2. **Radial Basis Functions**
Introduces RBF kernels for mapping input features to a higher-dimensional space for non-linear classification.
### 3. **Momentum Optimization**
Incorporates a momentum term into gradient descent to accelerate convergence and reduce oscillations.
### 4. **Hyperparameter Tuning**
Uses grid search to optimize hyperparameters such as the regularization coefficient and kernel bandwidth.
### 5. **Bayesian Logistic Regression**
Applies Laplacian approximation for a MAP estimate, improving model generalization with prior information.
## 📊 Results
**Key Observations:**
The use of RBFs improved classification accuracy on non-linearly separable datasets.
Momentum optimization accelerated convergence by approximately 30% compared to standard gradient descent.
Bayesian logistic regression with Laplacian approximation provided reliable uncertainty estimates for predictions.
**Example Performance:**
| Classifier Type |	Accuracy |
| ----- | ----- |
|Linear |	68%	| 
| Non-Linear (RBF)	|90%|
|Bayesian Extension	|91%|	

---
## 🚀 Future Work
**Multiclass Support:**

Extend the implementation to handle multi-class classification using one-vs-rest or softmax approaches.
**Bayesian Priors:**

Experiment with different prior distributions to refine Bayesian modeling.
**Interactive Visualizations:**

Develop tools to visualize decision boundaries and model uncertainties dynamically.

---

## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
