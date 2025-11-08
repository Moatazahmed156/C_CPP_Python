# Python Projects Collection

This repository contains **two Python projects**: a **Football Matches Scraper** and a **Guess the Number Game**.  
Both projects are beginner-friendly and showcase Python skills in **web scraping**, **file handling**, and **game logic**.

---

## Project 1: Football Matches Scraper

### 📝 Overview
This project scrapes football match details from [YallaKora](https://www.yallakora.com/match-center/) for a specific date and saves them to a CSV file.  

The data includes:
- Championship name
- Competing teams
- Match time
- Score
- Match status
- Round/week

It’s useful for **sports analysts, fans, or developers** who want automated football match data.

---

### ⚙ Features
- Enter a month and day to get match info for that date.
- Automatically validates the date.
- Retrieves multiple championships and all matches for each championship.
- Saves the result in **UTF-8 encoded CSV** for easy use in Excel or data analysis.

---

## Project 2: Guess the Number Game

### 📝 Overview
This is a **4-digit number guessing game** where each digit is unique. Players guess the number, and the game gives feedback on:

- **Placed** → Correct digit in the correct position.
- **True** → Correct digit in the wrong position.

The goal is to **guess the number before running out of tries**.

---

### ⚙ Features
- Generates a **random 4-digit number** with unique digits.
- Validates user input for:
  - 4-digit numbers only
  - No repeated digits
- Feedback system:
  - **Placed**: Number of digits in the correct place
  - **True**: Number of correct digits in the wrong place
- Users can specify the **number of attempts**.
