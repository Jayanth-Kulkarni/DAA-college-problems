Stable Matching
=========

stable marriage problem (SMP) is the problem of finding a stable matching between two sets of elements given a set of preferences for each element. A matching is a mapping from the elements of one set to the elements of the other set. A matching is stable whenever it is not the case that both:

* some given element  of the first matched set prefers some given element B of the second matched set over the element to which A is already matched, 
* B also prefers A over the element to which B is already matched
In other words, a matching is stable when there does not exist any alternative pairing (A, B) in which both A and B are individually better off than they would be with the element to which they are currently matched.

The stable marriage problem is commonly stated as
=============
* Given n men and n women, where each person has ranked all members of the opposite sex with a unique number between 1 and n in order of preference, marry the men and women together such that there are no two people of opposite sex who would both rather have each other than their current partners. If there are no such people, all the marriages are "stable". (It is assumed that the participants are binary gendered and that marriages are not same-sex).

Some more infornation
============
 Algorithms for finding solutions to the stable marriage problem have applications in a variety of real-world situations, perhaps the best known of these being in the assignment of graduating medical students to their first hospital appointments. In 2012, the Nobel Prize in Economics was awarded to Lloyd S. Shapley and Alvin E. Roth "for the theory of stable allocations and the practice of market design."

Reference
===========
* [Stable Marriage Problem](http://en.wikipedia.org/wiki/Stable_marriage_problem)
