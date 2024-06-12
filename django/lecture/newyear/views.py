from django.shortcuts import render
import datetime as dt

# Create your views here.
def index (request):
        current = dt.datetime.now()
        return render (request, "newyear/index.html", 
                {"newyear": current.day == 1 and current.month == 1 })# just added to try cs50's soln
        # if current.day == 1 and current.month == 1:
        #         return render(request, "newyear/true.html")
        # else:
        #         return render(request, "newyear/false.html", {
     
        #         "month": current.month,
        #         "day": current.day
        
                