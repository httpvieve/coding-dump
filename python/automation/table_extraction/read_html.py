import pandas as pd
moomin = pd.read_html('https://en.wikipedia.org/wiki/Moomin_(1990_TV_series)')

print(len(moomin))
print(moomin[0])