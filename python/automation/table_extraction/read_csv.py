import pandas as pd
# Reading 1 CSV file from the website
latest = pd.read_csv ('https://www.football-data.co.uk/mmz4281/2324/I1.csv')
print(latest)
# italy_matches = pd.read_csv('https://www.football-data.co.uk/italym.php')
# Rename unreadable column labels
latest.rename(columns={'MaxCAHH' : 'new_label1', 
                       'MaxCAHA' : 'new_label2'}, inplace = True) 
print(latest)
