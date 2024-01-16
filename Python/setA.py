import re
j = re.compile(r"^23((BCI)|(BCE)|(BCB)|(BKT))\d{4}$", re.IGNORECASE)
print("Valid" if j.match(input()) else "Invalid")
