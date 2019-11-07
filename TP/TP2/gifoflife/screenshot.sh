#!/bin/bash

# Change these values to match your preferences
imageQuality=100    # scrot default is 75
screenshotDir="/home/melon/University/S5/COOP/exo/TP2/gifoflife/"
imageName="$(date +%Y-%m-%d.%H:%M:%S.%N).jpg"   # save image names as timestamp
left=960     # begin crop this number of pixels from the left of the image
T=540      # begin crop this number of pixels from the T of the image 
width=780   # crop this many pixels wide
height=330  # crop this many pixels tall

#Do not make any more changes from here down unless you know what you're doing
imagePath="$screenshotDir/$imageName"

scrot -q $imageQuality "$imagePath"
convert "$imagePath" -crop ${width}x${height}+${left}+${T} "$imagePath"
