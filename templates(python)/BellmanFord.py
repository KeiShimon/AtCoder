from collections import defaultdict

'''
Bellmanford's algorithm.
This algorithm finds a minimum distances to each vertex from starting vertex.

This algorithm is useful when it is preknown that there can be a negative-cost edge.

Check if negative-loop exists before running search,
because if negative loop exists, search will enter infinite-loop.
'''


class BellmanFord():
    def __init__(self, n_nodes):
        self.edges = []
        self.n_nodes = n_nodes

    def add_edge(self, a, b, cost, directed=False):

        self.edges.append((a, b, cost))

        if not directed:
            self.edges.append((b, a, cost))

    def BellmanFord_search(self, start):
        """
        Returns min distances to every node from start node(input).\n
        """

        ditances = defaultdict(lambda: float('inf'))
        ditances[start] = 0

        while True:
            update = False

            for origin, destination, cost in self.edges:

                if ditances[origin] != float("inf"):
                    if ditances[destination] > ditances[origin] + cost:
                        ditances[destination] = ditances[origin] + cost
                        update = True

            if not update:
                break

        return ditances

    def negative_loop_exists(self):
        '''
        Detection of negative loop.\n
        Returns True if negative loop exists otherwise False.\n
        '''
        # O(|V||E|)

        ditances = defaultdict(lambda: float('inf'))
        ditances[0] = 0

        # loop for n times to know if node-update happens at nth iteration
        for i in range(self.n_nodes):
            for origin, destination, cost in self.edges:

                if ditances[destination] > ditances[origin] + cost:
                    ditances[destination] = ditances[origin] + cost
                    
                    # updating a node value(entering this if block) at i=n-1 happens if and only if there is a negative loop
                    if i == self.n_nodes-1:
                        return True

        return False