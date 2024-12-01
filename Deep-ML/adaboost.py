import numpy as np
import math

def adaboost_fit(X, y, n_clf):
    n_samples, n_features = np.shape(X)
    w = np.full(n_samples, (1 / n_samples))
    clfs = []
    for c in range(n_clf):
        clf={}
        min_error =float("inf")
        for feat in range(n_features):
            feat_values = np.expand_dims(X[:,feat],axis=1)
            unique = np.unique(feat_values)
            for thres in unique:
                p=1
                prediction = np.ones(np.shape(y))
                prediction[X[:,feat]<thres]=-1
                error = sum(w[y!=prediction])
                if error>0.5:
                    error=1-error
                    p=-1
                if error<min_error:
                    clf['polarity']=p
                    clf['threshold']=thres
                    clf['feature_index']=feat
                    min_error = error
        clf["alpha"] = 1/2 * np.log((1-min_error)/(min_error+1e-10))
        prediction = np.ones(np.shape(y))
        negative_idx = (clf["polarity"]*X[:,clf["feature_index"]]<clf["polarity"]*clf["threshold"])
        prediction[negative_idx]=-1
        w = w*np.exp(-clf["alpha"]*y*prediction)
        w=w/np.sum(w)
        clfs.append(clf)
    return clfs
