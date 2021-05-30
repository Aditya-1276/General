#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd


# In[2]:


import numpy as np


# In[24]:


import matplotlib.pyplot as plt


# In[3]:


df = pd.read_csv(r'\Users\adity\Downloads\tmdb-movies.csv')


# In[4]:


print(df)


# In[5]:


df.info()


# In[6]:


df.shape()


# In[7]:


df.shape


# In[8]:


df.describe()


# In[9]:


df.columns()


# In[10]:


df.columns


# In[11]:


df.head(10)


# In[12]:


df.tail(10)


# In[18]:


df.describe()


# In[20]:


df = df.drop_duplicates()


# In[21]:


df


# In[22]:


df = df.drop_duplicates(subset = ['original_title'])


# In[23]:


df


# In[25]:


df.boxplot(column = ['runtime'])


# In[26]:


df = df[(df['runtime'] >= 50) & (df['runtime'] <= 150)]


# In[27]:


df.boxplot(column = ['runtime'])


# In[28]:


df = df[(df['runtime'] >= 60) & (df['runtime'] <= 140)]


# In[29]:


df.boxplot(column = ['runtime'])


# In[30]:


df_new = df.drop(['id', 'imdb_id', 'popularity','homepage', 'director', 'tagline', 'keywords', 'overview','production_companies', 
                  'release_date','vote_count', 'vote_average', 'budget_adj','revenue_adj'], axis = 1)


# In[31]:


df_new


# In[32]:


df_new.describe()


# In[37]:


df_new.boxplot(column = ['budget'])


# In[38]:


df_new = df_new[df_new['budget'] >= 100000]


# In[39]:


df_new.describe()


# In[ ]:





# In[40]:


Budget_Array = df_new['budget'].unique()


# In[41]:


print(Budget_Array)


# In[42]:


Budget_Array.sort()


# In[43]:


print(Budget_Array)


# In[44]:


print(Budget_Array[2])     # Third Lowest Budget


# In[45]:


print(Budget_Array[-3])    # Third Highest Budget


# In[50]:


Runtime_df = df_new[df_new['release_year'] == 2006]


# In[51]:


Runtime_df


# In[52]:


Runtime_df.describe()


# In[ ]:


# Average Runtime = 103.069149


# In[54]:


df_new['revenue'].unique()


# In[62]:


df_new.boxplot(column = ['revenue'])


# In[63]:


df_new['revenue'].value_counts()


# In[64]:


df.head(20)


# In[66]:


df_new = df_new[df_new['revenue'] >= 15000]


# In[ ]:





# In[67]:


Revenue_Array = df_new['revenue'].unique()


# In[68]:


print(Revenue_Array)


# In[69]:


Revenue_Array.sort()


# In[70]:


print(Revenue_Array)


# In[71]:


Revenue_Array[:30]


# In[72]:


Revenue_Array[0]     


# In[73]:


df_new[df_new['revenue'] == 15071]     #Movie that earned the least revenue


# In[74]:


Revenue_Array[-1]


# In[ ]:





# In[75]:


df_new[df_new['revenue'] == 2068178225]     # Movie that earned the most revenue


# In[76]:


Names_df = df_new[(df_new['release_year'] >= 2000) & (df['release_year'] <= 2005)]


# In[77]:


Names_df


# In[78]:


Names_df.head(30)


# In[79]:


Names_df[Names_df["release_year"] == 2005]


# In[82]:


Names_Array = Names_df['original_title'].values.tolist()


# In[83]:


Names_Array


# In[84]:


No_of_Names = len(Names_Array)


# In[85]:


No_of_Names


# In[86]:


Names = ""


# In[88]:


for elt in Names_Array:
    Names += elt


# In[89]:


Names


# In[90]:


Word_Name_List = Names.split()


# In[91]:


Word_Name_List


# In[92]:


No_of_Words = len(Word_Name_List)


# In[93]:


No_of_Words


# In[94]:


Average_Number_of_Words = No_of_Words/No_of_Names


# In[95]:


Average_Number_of_Words     # The Average Number of Words in the Titles of Movies released from 2000-2005


# In[ ]:




