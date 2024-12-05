# 🤖 LLM Experiments

A collection of experimental projects exploring the capabilities and applications of Large Language Models (LLMs). These simple, unfinished projects serve as a learning tool for better understanding LLMs and their potential in various tasks.

## 📋 Table of Contents

- [Introduction](#introduction)
- [Projects Overview](#projects-overview)
  - [1. Building an LLM from Scratch](#1-building-an-llm-from-scratch)
  - [2. Educational LLM with RAG and LangChain](#2-educational-llm-with-rag-and-langchain)
  - [3. Fine-Tuning BERT for Sentiment Analysis](#3-fine-tuning-bert-for-sentiment-analysis)
- [Future Directions](#future-directions)
- [License](#license)

## 📖 Introduction

This repository houses three experimental projects focused on LLMs. These projects explore different aspects of working with LLMs, including building a model from scratch, integrating retrieval-augmented generation (RAG) for educational purposes, and fine-tuning a pretrained model for sentiment analysis.

## 🚀 Projects Overview

### 1. Building an LLM from Scratch

An attempt to understand the fundamentals of LLMs by constructing one from the ground up. The project involves implementing the key building blocks of a transformer-based architecture, including:

- Tokenization and embeddings
- Multi-head self-attention
- Training on a small custom dataset

This project is a work-in-progress and focuses on learning rather than scalability.

---

### 2. Educational LLM with RAG and LangChain

A project combining Retrieval-Augmented Generation (RAG) with LangChain to create a simple educational assistant. Key features include:

- **Document Retrieval:** Uses RAG to fetch relevant information from a custom corpus.
- **Conversational Interface:** Implements a LangChain-powered pipeline for generating answers to user queries.
- **Focus on Learning Applications:** Aimed at assisting users with specific topics.

---

### 3. Fine-Tuning BERT for Sentiment Analysis

This project fine-tunes a pretrained BERT model for sentiment analysis on text data. Highlights:

- **Dataset:** Fine-tuned on a labeled dataset of tweets.
- **Goal:** Perform live inference of sentiment on streaming tweets using PySpark.
- **Current Status:** Fine-tuning completed; streaming pipeline development in progress.

---

## 🌟 Future Directions

1. **LLM from Scratch:**
   - Train on larger datasets and improve scalability.
   - Integrate beam search for better output generation.

2. **Educational LLM:**
   - Add support for multimodal input (e.g., images and text).
   - Deploy as a chatbot with real-time querying capabilities.

3. **Sentiment Analysis:**
   - Complete the PySpark streaming pipeline.
   - Optimize for low-latency inference on real-time tweet streams.

---

## 📄 License

This repository is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
