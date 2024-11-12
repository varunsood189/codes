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
    if "Yes" in label_counter:
        px = label_counter["Yes"]/len(label)
        if px :    return -px*np.log2(px)
    return 0
    
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
	# select the att which gives the best reduction in entropy and continue
    if len(attributes)==0:
        return ""
    ig = {}
    for attr in attributes:
        ig[attr]= [Information_Gain(examples,attr,target_attr)]
    print(max(ig))
    decision_tree={}
    return decision_tree
    
# print(Entropy([label[target_attr] for label in examples ]))
# print(Information_Gain(examples,'Outlook',target_attr))
print(learn_decision_tree(examples, attributes, target_attr))


