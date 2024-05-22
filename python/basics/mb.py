dl_size = float(input())
mb_speed = float(input())
dl_current = float(input())
dl_rem = dl_size - dl_current
time_s = (dl_rem*8)/mb_speed
time_h = int(time_s/3600)
time_s -= time_h*3600 
time_m = int(time_s/60)
time_s -= time_m*60 
print("Progress: " + str(dl_current) + " / " + str(dl_size) + " MB (" + str(dl_current*100/dl_size) + "%), Remaining: " + str(dl_rem) + " MB, " + str(float(time_h)) + "h " + str(float(time_m)) + "m " + str(time_s) + "s")