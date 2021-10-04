#include <stdio.h>

int main{
    int divided1_match;
    
    for (int divided1_match = find_first_match(string, divided1, size - divided2_size, divided1_size);
        divided1_match > -1;
        divided1_match = ((temp = find_first_match(string + divided1_match + divided1_size, divided1, size - divided2_size - divided1_match - divided1_size + 1, divided1_size)) > -1 ?
        divided1_match + divided1_size + temp: temp)){
        int divided2_match = divided1_match + divided1_size + find_first_match(string + divided1_match + divided1_size, divided2, size - divided1_match - divided1_size + 1, divided2_size);
        if (divided2_match < divided1_match + divided1_size)
            continue;
        if (count_white_space_between(string + divided1_match, divided2_match - divided1_match) > 2)
            continue;
        count_of_search_string++;
        //concat matched_string
        if (count_of_search_string != 1){
            matched_string[matched_string_index] = ',';
            matched_string_index++;
            matched_string[matched_string_index] = ' ';
            matched_string_index++;
        }
        for (int i = divided1_match; i < divided2_match + divided2_size; ++i){
            matched_string[matched_string_index] = string[i];
            matched_string_index++;
        }
    }
    return 0;
}

