month_conversions = {
        "Jan": "January", # 1: January
        "Feb": "February", 
        "Mar": "March",
        "Apr": "April",
        "May": "May",
        "Jun": "June",
        "Jul": "July",
        "Aug": "August",
        "Sep": "September",
        "Oct": "October",
        "Nov": "November",
        "Dec": "December"
}
print(month_conversions["Feb"])
print(month_conversions.get("Feb"))
print(month_conversions.get("Tom", "Not a valid key"))