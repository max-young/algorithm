import unittest
from .quick_sort import quick_sort

class TestQuickSort(unittest.TestCase):
    def test_empty_array(self):
        self.assertEqual(quick_sort([]), [])

    def test_single_element_array(self):
        self.assertEqual(quick_sort([1]), [1])

    def test_sorted_array(self):
        self.assertEqual(quick_sort([1, 2, 3, 4, 5]), [1, 2, 3, 4, 5])

    def test_reverse_sorted_array(self):
        self.assertEqual(quick_sort([5, 4, 3, 2, 1]), [1, 2, 3, 4, 5])

    def test_unsorted_array(self):
        self.assertEqual(quick_sort([3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]), [1, 1, 2, 3, 3, 4, 5, 5, 5, 6, 9])

    def test_array_with_duplicates(self):
        self.assertEqual(quick_sort([3, 3, 3, 3, 3]), [3, 3, 3, 3, 3])

    def test_array_with_negative_numbers(self):
        self.assertEqual(quick_sort([-1, -3, -2, 0, 2, 1]), [-3, -2, -1, 0, 1, 2])

if __name__ == '__main__':
    unittest.main()