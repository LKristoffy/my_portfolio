Boston House Price Docker/K8 Deployment
==============================

A regression model deployment project using Docker on the Boston House Prices Dataset.

The project includes a simple training notebook in "notebooks" folder along with the python script to host the model API, DockerFile to containerise the API service and expose necessary ports and a .yaml file for K8s deployment in the "app" folder. 

To host this API service, a cloud kubernetes service can be used, for instance google cloud's GKE. Kubectl can then be used to deploy to cloud and scale/ clean up where necessary.

<p><small>Project based on the <a target="_blank" href="https://drivendata.github.io/cookiecutter-data-science/">cookiecutter data science project template</a>. #cookiecutterdatascience</small></p>
