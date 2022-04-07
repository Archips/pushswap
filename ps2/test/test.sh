#!/bin/bash
# echo "3 MAX" > 3
# for ((i = 0; i <= 200; i++)); do
#    ./push_swap `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"` | wc -l >> 3
# done

# echo "12 MAX" > 5
# for ((i = 0 ; i <= 200 ; i++)); do
#     ./push_swap `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"` | wc -l >> 5
# done

echo "700 MAX" > 100
for ((i = 0 ; i <= 20000 ; i++)); do
    ./push_swap `ruby -e "puts (-50..50).to_a.shuffle.join(' ')"` | wc -l >> 100
done

echo "5500 MAX" > 500
for ((i = 0 ; i <= 20000 ; i++)); do
    ./push_swap `ruby -e "puts (-250..250).to_a.shuffle.join(' ')"` | wc -l >> 500
done

