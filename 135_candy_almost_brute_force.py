# I don't like this solution but it is accepted
class Solution:
    def candy(self, ratings: List[int]) -> int:
        candies = [1] * len(ratings)

        if len(ratings) == 1:
            return 1

        i = 0
        while i < len(ratings):
            if i <= 0: # Most left
                if ratings[i] > ratings[i + 1]:
                    candies[i] = candies[i + 1] + 1
                else:
                    pass
            elif i >= len(ratings) - 1: # Most right
                if ratings[i] > ratings[i - 1]:
                    candies[i] = candies[i - 1] + 1
                else:
                    pass
            else: # Midle elemend we have left and right neighbours
                if ratings[i] > ratings[i - 1]:
                    if candies[i] <= candies[i - 1]:
                        candies[i] = candies[i - 1] + 1
                else:
                    pass

                if ratings[i] > ratings[i + 1]:
                    if candies[i] <= candies[i + 1]:
                        candies[i] = candies[i] + 1
                else:
                    pass
            i += 1

        ratings.reverse()
        candies.reverse()
        
        i = 0
        while i < len(ratings):
            if i <= 0: # Most left
                if ratings[i] > ratings[i + 1]:
                    candies[i] = candies[i + 1] + 1
                else:
                    pass
            elif i >= len(ratings) - 1: # Most right
                if ratings[i] > ratings[i - 1]:
                    candies[i] = candies[i - 1] + 1
                else:
                    pass
            else: # Midle elemend we have left and right neighbours
                if ratings[i] > ratings[i - 1]:
                    if candies[i] <= candies[i - 1]:
                        candies[i] = candies[i - 1] + 1
                else:
                    pass

                if ratings[i] > ratings[i + 1]:
                    if candies[i] <= candies[i + 1]:
                        candies[i] = candies[i] + 1
                else:
                    pass
            i += 1

        print(f'{candies}')
        return sum(candies)
