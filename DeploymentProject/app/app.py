from flask import Flask, request, jsonify
import joblib

app = Flask(__name__)

# Load the model
pipeline = joblib.load("BHPXGBoost.pkl")

@app.route("/predict", methods=["POST"])
def predict():
    try:
        # Check if JSON data is provided
        if not request.is_json:
            return jsonify({"error": "Request content-type must be application/json"}), 415
        
        
        # Extract data from request
        input_data = request.json.get("data")

        if input_data is None:
            return jsonify({"error": "JSON must include 'data' key"}), 400


        if not isinstance(input_data, list) or not isinstance(input_data[0], list) or not all((isinstance(x, (int, float)) for x in input_data[i]) for i in range(len(input_data))):
            return jsonify({"error": "Invalid data format. Must be a 2D list of numbers."}), 400

        # Prediction
        price_pred = pipeline.predict(input_data)
        
        return jsonify({'price_pred': price_pred.tolist()})  # Convert prediction to list for JSON response
    except Exception as e:
        return jsonify({"error": str(e)}), 400

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=9999, debug=False)
