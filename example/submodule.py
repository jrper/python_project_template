"""Example module in template package."""

from typing import TypeVar, Iterable, Tuple

import numpy

TNum = TypeVar('T', int, float, complex)
Vector = Iterable[Tuple[TNum, TNum]]

__all__ = ['cross_2d']

def cross_2d(vec1: Vector, vec2: Vector):
    """Return the z coordinate of a cross product for 2D vectors.

    >>> cross_2d((1, 0), (1, 0))
    array(0)
    >>> cross_2d((1, 0), (0, 1))
    array(1)
    """
    return numpy.array(vec1[0]*vec2[1]-vec1[1]*vec2[0])
