# 🏡 Boston House Price Docker/K8s Deployment
A regression model deployment project using Docker and Kubernetes, trained on the Boston House Prices dataset. This project demonstrates containerizing a machine learning model API and deploying it on a cloud-based Kubernetes service for scalability and management.

## 📋 Table of Contents

- [Introduction](#introduction)
- [Dataset](#dataset)
- [Features](#features)
- [Setup Instructions](#setup-instructions)
- [Google Cloud Kubernetes Deployment](#google-cloud-kuberentes-deployment)
- [Implementation Details](#implementation-details)
- [Results](#results)
- [Future Work](#future-work)
- [License](#license)
  
## 📖 Introduction
This project aims to deploy a regression model for predicting house prices using Docker and Kubernetes. The model API is containerized and can be scaled on cloud platforms like Google Kubernetes Engine (GKE) using kubectl. It serves as a practical demonstration of deploying machine learning solutions in production.

## 📁 Dataset
The project uses the Boston House Prices dataset, a classic dataset for regression tasks. It includes:

Features such as average number of rooms, neighborhood demographics, and proximity to employment centers.
Target: Median value of owner-occupied homes.
## ✨ Features
Regression Model:
Predicts house prices based on input features.
API Deployment:
A RESTful API for model predictions, hosted using Flask.
Containerization:
Dockerized API service for easy deployment and scalability.
Kubernetes Deployment:
Kubernetes YAML files for deployment and service configuration.
Scalability:
Scale the deployment using Kubernetes commands.
## ⚙️ Setup Instructions
Prerequisites
- Docker: Installed and running.
- Kubernetes CLI (kubectl): Installed and configured for a Kubernetes cluster.
- Google Cloud CLI (gcloud): Installed and authenticated.
- Google Cloud Project: Set up with billing enabled.
- Python: (>=3.8) Installed locally for training/testing.
- 
Steps to Deploy
Clone the Repository:



``git clone <repo-url>
cd <repo-name>``
Train the Model (Optional):

Navigate to the notebooks/ folder and run the training notebook.
Build the Docker Image:

``docker build -t <your-dockerhub-username>/boston_price_api:v1``
Push the Image to DockerHub:

bash
Copy code
docker push <your-dockerhub-username>/boston_price_api:v1
## ☁️ Google Cloud Kubernetes Deployment
Step 1: Set Up Google Kubernetes Engine (GKE)

Create a Google Cloud Kubernetes Cluster:

``gcloud container clusters create boston-price-cluster \
  --num-nodes=3 \
  --region=us-central1``
  
Configure kubectl for Your Cluster:


``gcloud container clusters get-credentials boston-price-cluster --region=us-central1``

Verify Cluster Connection:

``kubectl get nodes``

Step 2: Apply Kubernetes Deployment

Update Deployment Configuration:

Open app/deployment.yaml and ensure the image field matches your DockerHub image:

``image: <your-dockerhub-username>/boston_price_api:v1``

Apply Deployment and Service:

``kubectl apply -f app/deployment.yaml``

Expose the Service:

If not already exposed, you can expose the deployment:

``kubectl expose deployment boston-price-api --type=LoadBalancer --port=80 --target-port=5000``

Retrieve the External IP:

Get the external IP of the service to access your API:

``kubectl get services``

Test the API:

Use the external IP to send requests to the API, for example:

``curl -X POST http://<external-ip>/predict   -H "Content-Type: application/json"  -d '{"data": [[0.0063, 18.00, 2.310, 0.0, 0.4, 6.57, 65.0, 4.09, 1.0, 296.0, 15.5, 343.0, 5.0]]}'``

Step 3: Scale and Manage

Scale the Deployment:

``kubectl scale deployment boston-price-api --replicas=5``

Clean Up:


``kubectl delete -f app/deployment.yaml
gcloud container clusters delete boston-price-cluster --region=us-central1``

## 💻 Implementation Details
- Model Training:
A training notebook in the notebooks/ folder demonstrates preprocessing, training, and evaluation of the regression model.
- API Hosting:
Flask is used to serve the regression model as a REST API.
- Containerization:
The Dockerfile defines how the API is containerized and exposed on port 5000.
- Kubernetes Deployment:
The app/deployment.yaml file contains the configuration for deploying the containerized API to a Kubernetes cluster.
## 🚀 Future Work
- CI/CD Integration:
Automate deployment using CI/CD pipelines (e.g., GitHub Actions).
- Monitoring and Logging:
Integrate logging and monitoring tools like Prometheus and Grafana.
- Load Balancing:
Add advanced load balancing for high-traffic scenarios.
- Model Updates:
Implement strategies for seamless model updates in production.
## 📄 License
This project is licensed under the MIT License. See the LICENSE file for details.
