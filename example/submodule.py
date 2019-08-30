"""Example module in template package."""

from typing import TypeVar, Iterable, Tuple

T = TypeVar('T', int, float, complex)
Vector = Iterable[Tuple[T, T]]

import numpy

__all__ = ['cross_2d']

def cross_2d(a: Vector, b: Vector):
    """Return the z coordinate of a cross product for 2D vectors.
    
    >>> cross_2d((1, 0), (1, 0))
    0
    >>> cross_2d((1, 0), (0, 1))
    1
    """
    return a[0]*b[1]-a[1]*b[0]