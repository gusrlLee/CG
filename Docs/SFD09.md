# Spatial Splits in Bounding Volume Hierarchies 

authors: Martin Stich, Heiko Friedrich, and Andreas Dietrich. 
year: 2009. 
title: Spatial splits in bounding volume hierarchies. 
published in: In Proceedings of the Conference on High Performance Graphics 2009 (HPG '09). Association for Computing Machinery, New York, NY, USA, 7–13. 
url: https://doi.org/10.1145/1572769.1572771

In this paper, we propose a new method to significantly increase the efficiency of BVHs, especially for difficult scenes with highly non-uniform primitives sizes. 

The basic idea is to split a given node using either object list partitioning or spatial partitioning by selecting the more cost effective scheme.

basic paritioning algorithm
1. Find an object split candidate.
2. Find a spatial split candidate.
3. Select the winner candidate.

We adopt the binning idea for the spatial split search in the SBVH. Because SBVH nodes stores full bounding boxes and always tightly enclose their references, node children can adopted their size in all dimensions, not just in the split dimension.

Chopped binning: Primitives are clipped against each bin boundary, and the resulting boxes are used to grow the AABBs of the bins 

Such methods are not necessary in the SBVH build. If the best spatial split candidate is too costly, the obejct split candidate will simply be chosen instead. --> **항상 모든 node를 split 하는 것은 아님, Split하는 것은 cost가 비쌈!** 


