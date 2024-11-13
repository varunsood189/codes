examples = [
    {'Outlook': 'Sunny', 'Wind': 'Weak', 'PlayTennis': 'No'},
    {'Outlook': 'Overcast', 'Wind': 'Strong', 'PlayTennis': 'Yes'},
    {'Outlook': 'Rain', 'Wind': 'Weak', 'PlayTennis': 'Yes'},
    {'Outlook': 'Sunny', 'Wind': 'Strong', 'PlayTennis': 'No'},
    {'Outlook': 'Sunny', 'Wind': 'Weak', 'PlayTennis': 'Yes'},
    {'Outlook': 'Overcast', 'Wind': 'Weak', 'PlayTennis': 'Yes'},
    {'Outlook': 'Rain', 'Wind': 'Strong', 'PlayTennis': 'No'},
    {'Outlook': 'Rain', 'Wind': 'Weak', 'PlayTennis': 'Yes'}
]
attributes =  ['Outlook', 'Wind'] 
target_attr="PlayTennis"
# solution : {'Outlook': {'Sunny': 
# {'Wind':
#     {'Weak':    'No',
#     'Strong': 'No'}}, 
# 'Rain':
#     {'Wind': 
#         {'Weak': 'Yes',
#         'Strong': 'No'}}, 
# 'Overcast': 'Yes'}}
import numpy as np
from collections import Counter
import math
def Entropy(label):
    label_counter = Counter(label)
    prob = [ label_counter[l]/len(label) for l  in label_counter]
    return sum([-px*np.log2(px) for px in prob])
    
def Information_Gain(examples,attr,target_attr): 
    total_entropy=Entropy([label[target_attr] for label in examples ])
    attribute_dict = {}
    sample =[]
    for example in examples:
        if example[attr] in attribute_dict: 
            attribute_dict[example[attr]]+=[example[target_attr]]
        else:
            attribute_dict[example[attr]]=[example[target_attr]]
    for key, value in attribute_dict.items():
        # print(key,value,Entropy(value))
        total_entropy-=len(value)/len(examples)* Entropy(value)
    return total_entropy

def learn_decision_tree(examples: list[dict], attributes: list[str], target_attr: str) -> dict:

    if all([example[target_attr]==examples[0][target_attr] for example in examples ]):
        return examples[0][target_attr]
    if len(attributes)==0:
        return Counter([example[target_attr] for example in examples ]).most_common(1)[0][0]
    ig = {}
    for attr in attributes:
        ig[attr]= [Information_Gain(examples,attr,target_attr)]
    best_attr = max(ig,key=ig.get)
    decision_tree = {best_attr: {}}

    dict_labels={}
    attributes_copy = attributes.copy()
    attributes_copy.remove(best_attr)
    for data in examples:
        if data[best_attr] in dict_labels:
            dict_labels[data[best_attr]]+=[data]    
        else:
            dict_labels[data[best_attr]]=[data]  
    for l in list(dict_labels.keys()):
        subtree =  learn_decision_tree(dict_labels[l],attributes_copy,target_attr)
        decision_tree[best_attr][l] = subtree
    return decision_tree
    
# print(Entropy([label[target_attr] for label in examples ]))
# print(Information_Gain(examples,'Outlook',target_attr))
print(learn_decision_tree(examples, attributes, target_attr))
