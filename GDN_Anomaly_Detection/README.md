# 📊 Graph Neural Network (GDN) for Multivariate Time Series Anomaly Detection
A project that implements a graph neural network (GDN) to detect anomalies in multivariate time series data. This study was applied to a synthetic dataset from Kaggle and includes a baseline comparison using Principal Component Analysis (PCA).

## 📋 Table of Contents

- [Introduction](#introduction)
- [Dataset](#dataset)
- [Features](#features)
- [Setup Instructions](#setup-instructions)
- [Implementation Details](#implementation-details)
- [Results](#results)
- [Challenges](#challenges)
- [Future Work](#future-work)
- [License](#license)
## 📖 Introduction
This project explores the use of a graph neural network for anomaly detection in multivariate time series data. It utilizes the relationships between features (sensors) to construct a dynamic graph and detect deviations from normal behavior. The anomaly score is computed based on the deviation at each time step.

While GDN has shown strong performance on other datasets, this implementation on a synthetic dataset yielded suboptimal results, potentially due to limitations in the dataset's ability to capture meaningful inter-sensor relationships.

## 📁 Dataset
The dataset used in this project is a synthetic multivariate time series dataset sourced from Kaggle.

Key characteristics:

- Multiple time series features representing synthetic sensors.
- Includes labeled anomalies for evaluation.
## ✨ Features
1. Graph Neural Network (GDN):

- Captures inter-sensor relationships via graph-based modeling.
- Employs attention mechanisms for learning edge weights dynamically.
2. Baseline Comparison:

- PCA-based anomaly detection.
- Simple reconstruction error serves as the anomaly score.
3. Dynamic Graph Construction:

- Uses cosine similarity to construct a graph structure between sensors dynamically.
4. Anomaly Scoring:

- Deviation from normal behavior at each time step is computed as the anomaly score.
## ⚙️ Setup Instructions
Prerequisites
- Python (>= 3.8)
- PyTorch (>= 1.10)
- Torch-Geometric (>= 2.1)
- Jupyter Notebook (optional, for running the notebooks)


## 💻 Implementation Details
1. Data Preprocessing:

- Normalized the time series data for consistent feature scaling.
- Constructed a graph structure based on cosine similarity of sensor data.
2. Model Training:

- Implemented a GDN as described in the research paper: Graph Neural Network-Based Anomaly Detection in Multivariate Time Series.
- Trained the model using cross-entropy loss for anomaly prediction.
3. Baseline Comparison:

- PCA-based reconstruction error used as a baseline anomaly detection method.
4. Evaluation:

- Used metrics such as precision, recall, and F1-score to evaluate anomaly detection performance.
## 📊 Results
- GDN:

Performance on synthetic data was not satisfactory, with low anomaly detection precision.
Likely due to the synthetic dataset's inability to represent meaningful inter-sensor relationships.
- PCA Baseline:

Achieved marginally better results than GDN but still limited in detecting anomalies effectively.
- Observations:
Results do not reflect the strong performance of GDN on real-world datasets where inter-sensor relationships are more meaningful.
## 🛠️ Challenges
- Synthetic Nature of Dataset: The synthetic dataset may lack realistic inter-sensor correlations, limiting the ability of the GDN to leverage graph-based relationships.
- Data Quality: Limited variety and complexity in the dataset reduce the generalizability of results.
## 🚀 Future Work
- Real-World Dataset:

Apply the GDN model to real-world multivariate time series datasets with stronger inter-sensor relationships.
- Meta-Learning:

Investigate meta-learning approaches to adapt the GDN to new operating environments more efficiently.
- Dynamic Dataset Generation:

Create synthetic datasets with better inter-sensor relationships for improved benchmarking.
- Anomaly Explanation:

Enhance interpretability by leveraging attention weights to explain detected anomalies.
## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.
