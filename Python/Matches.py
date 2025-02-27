import requests
from bs4 import BeautifulSoup
import csv
import calendar

this_year = 2025
def get_valid_date():
    month = int(input("Enter Month (1-12): "))
    if month < 1 or month > 12:
        month = 12
    max_day = calendar.monthrange(this_year, month)[1]
    day = int(input(f"Enter Day (1-{max_day}): "))
    if day < 1 or day > max_day:
        day = max_day
    
    return month, day

month, day = get_valid_date()

page = requests.get(F"https://www.yallakora.com/match-center/?date={month}/{day}/{this_year}#days")

def main(page):
    if page.status_code != 200:
        print("Failed to retrieve the page.")
        return

    src = page.content
    beauty = BeautifulSoup(src, "html.parser")
    matches_details = []

    championships = beauty.find_all("div", {'class': 'matchCard'})
    if not championships:
        print("No matches found for the specified date.")
        return

    def get_match_info(championship):
        try:
            championship_title = championship.contents[1].find('h2').text.strip()
            all_matches = championship.contents[3].find_all("div", {'class': 'item'})
        except (IndexError, AttributeError):
            return  

        for match in all_matches:
            try:
                team_A = match.find('div', {'class': 'teamA'}).text.strip()
                team_B = match.find('div', {'class': 'teamB'}).text.strip()

                match_result = match.find('div', {'class': 'MResult'}).find_all('span', {'class': 'score'})
                score = f"{match_result[0].text.strip()} - {match_result[1].text.strip()}"

                match_time = match.find('div', {'class': 'MResult'}).find('span', {'class': 'time'}).text.strip()

                
                match_status = match.find('div', {'class': 'matchStatus'}).text.strip()
                match_date = match.find('div', {'class': 'date'}).text.strip()

                matches_details.append({
                    "نوع البطولة": championship_title,
                    "الفريق الأول": team_A,
                    "الفريق الثانى": team_B,
                    "ميعاد المباراة": match_time,
                    "النتيجة": score,
                    "حالة المباراة": match_status,
                    "الجولة/الأسبوع": match_date
                })
            except AttributeError:
                continue  
    for championship in championships:
        get_match_info(championship)

    if matches_details:
        keys = matches_details[0].keys()
        with open('kora.csv', 'w', encoding="utf-8-sig") as output_file:
            dict_writer = csv.DictWriter(output_file, keys)
            dict_writer.writeheader()
            dict_writer.writerows(matches_details)
        print("CSV file created successfully.")
    else:
        print("No match data to write.")

main(page)