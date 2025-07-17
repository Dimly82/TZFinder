import json

rus_regions = ["Europe/Kaliningrad", "Europe/Simferopol", "Europe/Moscow", "Europe/Volgograd", "Europe/Astrakhan",
               "Europe/Saratov", "Europe/Ulyanovsk", "Europe/Samara", "Europe/Kirov",
               "Asia/Yekaterinburg", "Asia/Omsk", "Asia/Krasnoyarsk", "Asia/Novosibirsk", "Asia/Novokuznetsk",
               "Asia/Barnaul", "Asia/Tomsk",
               "Asia/Irkutsk", "Asia/Chita", "Asia/Yakutsk", "Asia/Khandyga", "Asia/Ust-Nera", "Asia/Vladivostok",
               "Asia/Magadan", "Asia/Sakhalin", "Asia/Srednekolymsk", "Asia/Anadyr", "Asia/Kamchatka"]

with open("../data/combined-with-oceans.json", "r", encoding="utf-8") as f:
    data = json.load(f)

filtered_features = [
    feat for feat in data["features"]
    if feat.get("properties", {}).get("tzid", "") in rus_regions]

filtered = {
    "type": "FeatureCollection",
    "features": filtered_features
}

with open("russia-timezones.json", "w", encoding="utf-8") as f:
    json.dump(filtered, f)
