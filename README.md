# TicTacToe-Evolutionary-Algorithm

This was an implementation of an evolutionary algorithm to find an AI who can learn to play TicTacToe. Using an intial population size ranging from 500 to 1000, every AI would play each other round robin style. The most fit AIs would be sampled and bred to create children and the least fit AIs would be deleted. Children would have a small chance to mutate, slightly altering their heuristic. Fitness was determined by wins minus losses + a small amount for ties. The heuristic being developed was one which took into account several things about the board state. The ideal situation would be to eventually develop an AI which would have the best weight value / heuristic for evaluating that board state. 

