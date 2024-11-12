examples = [
    {'Outlook': 'Sunny', 'Temperature': 'Hot', 'Humidity': 'High', 'Wind': 'Weak', 'PlayTennis': 'No'},
    {'Outlook': 'Sunny', 'Temperature': 'Hot', 'Humidity': 'High', 'Wind': 'Strong', 'PlayTennis': 'No'},
    {'Outlook': 'Overcast', 'Temperature': 'Hot', 'Humidity': 'High', 'Wind': 'Weak', 'PlayTennis': 'Yes'},
    {'Outlook': 'Rain', 'Temperature': 'Mild', 'Humidity': 'High', 'Wind': 'Weak', 'PlayTennis': 'Yes'}
]
attributes = ['Outlook', 'Temperature', 'Humidity', 'Wind']
target_attr="PlayTennis"

import numpy as np
from collections import Counter
import math
def Entropy(label):
    label_counter = Counter(label)
    if "Yes" in label_counter:
        px = label_counter["Yes"]/len(label)
        if px :    return -px*np.log2(px)
    return 0
    
def Information_Gain(examples,attr,target): 
    total_entropy=Entropy(examples)
    attribute_dict = {}
    sample =[]
    for example in examples:
        if example[attribute] in attribute_dict: 
            attribute_dict[example[attribute]]+=[example]
        else:
            attribute_dict[example[attribute]]=[example]
    for key, value in attribute_dict.items():
        print(key,Entropy(value))
        ig-=len(value)/len(examples)* Entropy(value)
    return ig

def learn_decision_tree(examples: list[dict], attributes: list[str], target_attr: str) -> dict:
	
	# Your code here
	decision_tree={}
	
	return decision_tree
# print(learn_decision_tree(examples, attributes, target_attr))
print(Information_Gain(examples,attributes,target_attr))
# print(Entropy([label[target_attr] for label in examples ]))


