library(xlsx)
mydata   <- read.xlsx("edeitedDataset.xls",1,startRow = 4, endRow = 25, colIndex = 1:12 )
#years     <- mydata[,1]
years      <- 1994:2014
population <- mydata[,2]
totalCrime <- mydata[,12]


linearmodule <- lm(totalCrime ~ years+population)

Intercept <- linearmodule$coefficients[1]
yearsCo <- linearmodule$coefficients[2]
populationCo <- linearmodule$coefficients[3]

R_squre <- as.numeric(summary(linearmodule)$r.squared)*100

print(R_squre)

#print(linemodule)
#T <- -41.5 * years + 0.184 * ( population /100000 ) + 84796 
#T <-  ( yearsCo* years + populationCo * ( population ) + Intercept ) 

#par(mfrow=c(2,2))
#plot(linearmodule)


par(mfrow=c(1,1))
plot(years,totalCrime)
points(sort(years), linearmodule$fitted[order(years)], type = "l")





# testing data 

testdata <- read.xlsx("edeitedDataset.xls",1,startRow = 25, endRow = 27, colIndex = 1:12 )

testYears <-2016:2017
testpopulation <- testdata[,2]
actualCrimes <-testdata[,12]
  

expectedCrime <-  ( (yearsCo * testYears) + (populationCo * testpopulation ) + Intercept ) 
print(expectedCrime)
print(actualCrimes)
errors <- ((actualCrimes - expectedCrime)/actualCrimes)*100
print(errors)
