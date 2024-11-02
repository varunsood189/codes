def compute_tf_idf(corpus, query):
    """
    Compute TF-IDF scores for a query against a corpus of documents.
    
    :param corpus: List of documents, where each document is a list of words
    :param query: List of words in the query
    :return: List of lists containing TF-IDF scores for the query words in each document
    """
    tf = [[0 for i in range(len(query))] for j in range(len(corpus))]
    idf = [0]*len(query)
    for i,q in enumerate(query):
        doc_query = 0

        for j,doc in enumerate(corpus):
            if q in doc:
                doc_query+=1
            tf[j][i]= doc.count(q)/len(doc)
        idf[i] =  np.log((len(corpus)+1)/(doc_query+1))+1
    # print(np.array(tf))
    # print(idf)
    return [[round(value*idf[0],5) for value in row] for row in tf]
