# 🚀 Machine Learning Portfolio

Welcome to my Machine Learning Portfolio! This repository showcases a diverse range of projects highlighting my expertise in deploying, experimenting, and developing cutting-edge machine learning solutions. Each project includes detailed documentation for reproducibility and scalability.

---

## 📋 Table of Contents

1. [📖 Overview](#-overview)  
2. [🌟 Featured Projects](#-featured-projects)  
   - [🏡 Boston House Price Docker/K8s Deployment](#-boston-house-price-dockerk8s-deployment)  
   - [📊 Graph Neural Network (GDN) for Multivariate Time Series Anomaly Detection](#-graph-neural-network-gdn-for-multivariate-time-series-anomaly-detection)  
   - [🤖 LLM Experiments](#-llm-experiments)  
   - [🧠 Logistic Classifier with RBF Extensions](#-logistic-classifier-with-rbf-extensions)  
3. [📞 Contact](#-contact)  

---

## 📖 Overview

This portfolio demonstrates my expertise in a wide array of machine learning domains, including:  
- Model deployment with Docker and Kubernetes.
- Contrastive learning with SimCLR on the HAM10000 dataset.
- Graph-based deep learning for anomaly detection.
- Efficient and distributed training of a movie recommender system leveraging PySpark.
- Experimentation with advanced neural network architectures, including LLMs.  
- Bayesian optimization and kernel methods for classification.  

Each project serves as a showcase of my skills in data preprocessing, model development, deployment, and experimentation, focusing on real-world applications and performance optimization.

---

## 🌟 Featured Projects

### 🏡 Boston House Price Docker/K8s Deployment

**Description:**  
This project demonstrates the deployment of a regression model for predicting house prices. Leveraging Docker and Kubernetes, the model API is containerized and deployed on Google Kubernetes Engine for scalability and management.  

**Key Features:**  
- Flask-based API for predictions.  
- Containerization with Docker.  
- Scalable deployment using Kubernetes.  

**Tech Stack:**  
Python, Flask, Docker, Kubernetes, Google Cloud Platform.  

[**View Project Details**](./DeploymentProject)

---

### 🖼️ SimCLR-Based Contrastive Learning for Image Representation

**Description:**  
A self-supervised learning project utilizing SimCLR for robust image representation learning. This project uses contrastive learning with augmented views of images to pretrain an encoder, which is evaluated through downstream classification tasks.  

**Key Features:**  
- Contrastive learning with extensive data augmentations.  
- Projection head for improved representation alignment.  
- Linear probing for evaluation on labeled datasets.  

**Tech Stack:**  
Python, TensorFlow, NumPy, Matplotlib.  

[**View Project Details**](./SimCLR_HAM10000)


---

### 📊 Graph Neural Network (GDN) for Multivariate Time Series Anomaly Detection

**Description:**  
Implementation of a GDN model for anomaly detection in multivariate time series data. This project includes baseline comparisons using PCA and highlights challenges when applying GDN to synthetic datasets.  

**Key Features:**  
- Dynamic graph construction using cosine similarity.  
- Attention mechanisms for anomaly detection.  
- Baseline PCA model for reconstruction error.  

**Tech Stack:**  
Python, PyTorch, PyTorch Geometric.  

[**View Project Details**](./GDN_Anomaly_Detection)

---
### 🎥 Movie Recommendation System with PySpark

**Description:**  
A collaborative filtering-based movie recommendation system leveraging PySpark's MLlib. The system uses the Alternating Least Squares (ALS) algorithm to generate personalized movie suggestions based on user-movie interaction data.  

**Key Features:**  
- ALS-based collaborative filtering model.  
- Scalable data preprocessing using PySpark.  
- Hyperparameter tuning for improved accuracy.  
- Visualizations of user activity and rating trends.  

**Tech Stack:**  
Python, PySpark, Matplotlib, Seaborn.  

[**View Project Details**](./PySpark_Projects/MovieRecommender)

---
### 🤖 LLM Experiments

**Description:**  
Experiments with large language models (LLMs) focusing on fine-tuning and adapting pre-trained transformer architectures for domain-specific tasks.  

**Key Features:**  
- Custom pre-training pipelines.  
- Model evaluation with real-world datasets.  
- Comparative analysis of LLM architectures.  

**Tech Stack:**  
Python, Hugging Face Transformers, TensorFlow/PyTorch.  

[**View Project Details**](./LLMExperiments)

---

### 🧠 Logistic Classifier with RBF Extensions

**Description:**  
Implementation of a logistic classifier with advanced features, including radial basis functions (RBF) for non-linear decision boundaries, momentum optimization, and Bayesian inference with Laplace approximation.  

**Key Features:**  
- Momentum-based parameter optimization.  
- Bayesian hyperparameter tuning.  
- Visualization of decision boundaries and predictive uncertainty.  

**Tech Stack:**  
Python, NumPy, Matplotlib, Scikit-learn.  

[**View Project Details**](./Laplace_Bayesian_Logisitc_Classifier)

---

## 📞 Contact

Feel free to reach out for collaborations, questions, or opportunities!  

- **Email:** liam@kristoffy.com  
- **LinkedIn:** [Liam Kristoffy](https://www.linkedin.com/in/liam-kristoffy/)  
- **GitHub:** [LKristoffy](https://github.com/LKristoffy)  

---

✨ Thank you for exploring my portfolio! I look forward to your feedback and collaboration opportunities. ✨
