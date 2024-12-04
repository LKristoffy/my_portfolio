# 🎥 Movie Recommendation System

A collaborative filtering-based movie recommendation system built using PySpark's MLlib library. This project processes a large-scale dataset and uses the Alternating Least Squares (ALS) algorithm to recommend movies to users based on their preferences.

## 📋 Table of Contents

- [Introduction](#introduction)
- [Dataset](#dataset)
- [Features](#features)
- [Setup Instructions](#setup-instructions)
- [Implementation Details](#implementation-details)
- [Results](#results)
- [Future Work](#future-work)
- [License](#license)

## 📖 Introduction

This project builds a movie recommendation system using collaborative filtering. By leveraging user-movie interaction data, it predicts user preferences and generates personalized movie suggestions. The implementation demonstrates the power of PySpark for processing large-scale data and training machine learning models in a distributed environment.

## 📁 Dataset

The project uses the MovieLens dataset, a widely-used benchmark dataset for recommendation systems. It includes:

Ratings Data: User ratings for movies.
Movies Data: Movie titles and genres.

## ✨ Features

Collaborative Filtering:

1. Built using the ALS algorithm from PySpark MLlib.
Data Processing:

2. Handled missing values and filtered inactive users/movies.
Exploratory Data Analysis (EDA):

3. Visualized user activity and rating distributions.
Model Training:

4. Trained the ALS model with hyperparameter tuning.
Recommendations:

5. Provided personalized movie recommendations for users.
   
## ⚙️ Setup Instructions

Prerequisites:

Python (>= 3.8)
PySpark (>= 3.3.0)
Java (>= 11)
Jupyter Notebook (optional, for running the notebook)


## 💻 Implementation Details

1. Data Preprocessing:

- Loaded ratings and movie data using PySpark's DataFrame API.
- Performed data cleaning and filtering for efficient model training.
2. Model Training:

- Used the ALS algorithm from PySpark MLlib.
- Tuned hyperparameters such as rank, regParam, and maxIter.
3. Recommendations:

- Generated top-N movie recommendations for a sample of users.
- Evaluated the model using RMSE.
4. Visualization:

- Plotted trends in movie ratings and user activity using Matplotlib and Seaborn.

## 📊 Results

The ALS model provided personalized movie recommendations with reasonable accuracy:

Model Evaluation:
RMSE: ~0.8 (depending on hyperparameters and dataset size).
Sample recommendations for a user:

| Movie Title	Predicted | Rating |
| -------- | ---------- |
| The Matrix (1999)	    | 4.8 |
| Inception (2010)	    | 4.6 |
| Interstellar (2014)	  | 4.5 |


## 🚀 Future Work

1. Content-Based Filtering:

- Incorporate movie genres and metadata for hybrid recommendations.
2. Scalability:

- Optimize the model for larger datasets or use a distributed cluster.
3. Web Application:

- Create a user interface using Flask or Django for interactive recommendations.
🛠️ Technologies Used
- PySpark: Distributed data processing and machine learning.
- Python: Data analysis and scripting.
- Matplotlib/Seaborn: Data visualization.
- Jupyter Notebook: Development and experimentation.
  
## 📄 License
 
This project is licensed under the MIT License - see the LICENSE file for details.
