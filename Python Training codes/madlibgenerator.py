from random import randint

def random_verb():
    random_num = randint(0, 1)
    if random_num == 0:
        return "run"
    else:
        return "kayak"
        
def random_noun():
    random_num = randint(0,1)
    if random_num == 0:
        return "sofa"
    else:
        return "llama"

def word_transformer(word):
    if word == "NOUN":
        return random_noun()
    elif word == "VERB":
        return random_verb()
    else:
        return word[0]

def process_madlib(mad_lib):
    processed = ""
    i = 0
    window = 4
    while i < len(mad_lib):
        frame = mad_lib[i : i + window]
        to_add = word_transformer(frame)
        processed += to_add
        if len(to_add) == 1 :
            i += 1
        else :
            i += 4
    return processed
        
#def process_madlib(mad_lib):
#    position1 = mad_lib.find('NOUN')
#    position2 = mad_lib.find('VERB')

#    processed = mad_lib.replace()
#    i = 1
#    if processed == 'NOUN':

#    or processed == 'VERB':

    
test_string_1 = "This is a good NOUN to use when you VERB your food"
test_string_2 = "I'm going to VERB to the store and pick up a NOUN or two."
print process_madlib(test_string_1)
print process_madlib(test_string_2)
