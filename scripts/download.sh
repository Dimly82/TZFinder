#!/bin/bash
set -e

mkdir -p data

URL="https://github.com/evansiroky/timezone-boundary-builder/releases/latest/download/timezones-with-oceans.geojson.zip"
ZIP_FILE="./data/timezones.geojson.zip"

echo "📦 Downloading with curl..."
curl -L --fail --progress-bar "$URL" -o "$ZIP_FILE"

if file "$ZIP_FILE" | grep -q "Zip archive data"; then
    echo "✅ Downloaded ZIP, extracting..."
    unzip -o "$ZIP_FILE" -d data
    rm "$ZIP_FILE"
    echo "✅ Successfully extracted!"
else
    echo "❌ Error: Downloaded file is not a valid ZIP!"
    rm -f "$ZIP_FILE"
    exit 1
fi