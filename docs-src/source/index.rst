.. DocExample documentation master file, created by
   sphinx-quickstart on Thu Nov 25 12:50:57 2021.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

Welcome to DocExample's documentation!
======================================

.. toctree::
   :maxdepth: 2
   :caption: Contents:



Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

H2 -- Page Sections
===================

H3 -- Subsection
----------------

COMPLEX TABLE:

+------------+------------+-----------+
| Header 1   | Header 2   | Header 3  |
+============+============+===========+
| body row 1 | column 2   | column 3  |
+------------+------------+-----------+
| body row 2 | Cells may span columns.|
+------------+------------+-----------+
| body row 3 | Cells may  | - Cells   |
+------------+ span rows. | - contain |
| body row 4 |            | - blocks. |
+------------+------------+-----------+

SIMPLE TABLE:

=====  =====  ======
   Inputs     Output
------------  ------
  A      B    A or B
=====  =====  ======
False  False  False
True   False  True
False  True   True
True   True   True
=====  =====  ======

H4 -- Subsubsection
+++++++++++++++++++

.. _is_sweaty:
.. figure::  https://pythonhosted.org/an_example_pypi_project/_images/sweat.jpg
   :align:   center

   Proof that getting rich is mostly luck.