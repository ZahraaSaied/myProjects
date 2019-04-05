import sys
maximum = 0.0
oldKey = None
dummy_Data=["Miami 512.34",
            "Miami 909.07",
            "Miami 155.07",
            "NYC 808.97",
            "NYC 173.56",
            "OZ 5932.56",
            "OZ 613.56"]

for line in dummy_Data:
  data = line.strip().split(" ")
  if len(data) != 2:
    # Something has gone wrong. Skip this line.
    continue
  thisKey, thisSale = data
  if thisKey == oldKey:
    #print "be",maximum
    maximum = max(maximum, float(thisSale))
    #print "af",maximum

  if oldKey and thisKey != oldKey:
    print oldKey, "\t", maximum
    maximum = float(thisSale)
    oldKey = thisKey

  if oldKey is None:
    oldKey = thisKey
    maximum = float(thisSale)

if oldKey != None:
  print oldKey, ":", maximum