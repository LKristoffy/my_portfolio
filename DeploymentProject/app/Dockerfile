# Base image
FROM python:3.9-slim

# Set working directory
WORKDIR /app

# Copy necessary files
COPY . .

# Install dependencies
RUN pip install --upgrade numpy==1.22.4 scikit-learn==1.0.2 xgboost flask gunicorn joblib

# Expose port
EXPOSE 9999:9999

# Run the Flask app
CMD ["gunicorn", "-w", "4", "-b", "0.0.0.0:9999", "app:app"]
