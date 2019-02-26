#  Decision Tree

# Importing the libraries
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# Importing the dataset
dataset = pd.read_csv('Position_Salaries.csv')
X = dataset.iloc[:, 1:2].values
y = dataset.iloc[:, 2].values

# Fitting the Decision Tree Regression Model to the dataset
from sklearn.tree import DecisionTreeRegressor
regressor = DecisionTreeRegressor(random_state = 0)
regressor.fit(X, y)

# Predicting a new result
y_pred = regressor.predict(np.array([[6.5]]))


# Visualising the Decision Tree Regression results (for higher resolution and smoother curve)
x_grid = np.arange(min(X), max(X), 0.01)
x_grid = x_grid.reshape((len(x_grid), 1))
plt.scatter(X, y, color = 'red')
plt.plot(x_grid, regressor.predict(x_grid), color = 'blue')
plt.title('Truth or Bluff (Decision Tree Model)')
plt.xlabel('Position level')
plt.ylabel('Salary')
plt.show()