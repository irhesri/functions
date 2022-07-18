#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>

//	BRANCHLESS
int	min(int a, int b);
int	max(int a, int b);
int	absolute_value(int a);

//	NO COMPARISON OPERATORS
int	_min(int a, int b);
int	_max(int a, int b);
int	_absolute_value(int a);

#endif