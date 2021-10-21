#!/usr/bin/env python
# coding: utf-8

# In[4]:


import numpy as np
import pandas as pd
import seaborn as sns


# In[5]:


HnO = pd.read_csv('Nutrition and Obesity.csv')


# In[6]:


HnO.head()


# In[7]:


new_HnO = HnO.drop(['Data_Value_Unit'], axis = 1)


# In[8]:


new_HnO.head()


# In[9]:


new_HnO.columns


# In[10]:


new_HnO.info()


# In[11]:


new_HnO.tail()


# In[12]:


new_HnO = new_HnO.fillna(0)


# In[13]:


new_HnO.nunique()


# In[14]:


new_HnO['DataValueTypeID']


# In[15]:


new_HnO = new_HnO.drop(['DataValueTypeID' , 'Data_Value_Type'], axis = 1)


# In[16]:


new_HnO.isnull().sum()


# In[17]:


Tot = new_HnO['Total']


# In[18]:


type(Tot)


# In[19]:


Tot.tolist()


# In[20]:


new_HnO['Datasource']


# In[21]:


new_HnO = new_HnO.drop(['Total' , 'Datasource'], axis = 1)


# In[22]:


new_HnO.nunique()


# In[23]:


new_HnO['Data_Value_Footnote']


# In[24]:


new_HnO = new_HnO.drop(['Data_Value_Footnote_Symbol' , 'Data_Value_Footnote' , 'Age(years)' , 'Education' , 'Gender' , 'Income' , 'Race/Ethnicity' , 'LocationID' , 'ClassID' , 'TopicID' , 'QuestionID'] , axis = 1)


# In[25]:


new_HnO.head()


# In[26]:


new_HnO.shape


# In[27]:


new_HnO.tail()


# In[29]:


new_HnO = new_HnO.drop(['Sample_Size' , 'GeoLocation' , 'StratificationCategoryId1' , 'StratificationID1'] , axis = 1)


# In[30]:


sns.pairplot(new_HnO)


# In[32]:


new_HnO.columns


# In[46]:


new_HnO.info()


# In[47]:


new_HnO.head()


# In[48]:


new_HnO.boxplot(column = ['Data_Value'])


# In[52]:


new_HnO = new_HnO[(new_HnO['Data_Value'] >= 10) & (new_HnO['Data_Value'] <= 60)]


# In[53]:


new_HnO.shape


# In[54]:


new_HnO.boxplot(column = ['Data_Value'])


# In[57]:


new_HnO = new_HnO[(new_HnO['Data_Value'] >= 10) & (new_HnO['Data_Value'] <= 55)]


# In[58]:


new_HnO.boxplot(column = ['Data_Value'])


# In[60]:


new_HnO = new_HnO.drop(['Data_Value_Alt'] , axis = 1)


# In[61]:


new_HnO.boxplot(column = ['Low_Confidence_Limit'])


# In[62]:


new_HnO = new_HnO[(new_HnO['Data_Value'] >= 10) & (new_HnO['Data_Value'] <= 50)]


# In[63]:


new_HnO.info()


# In[67]:


new_HnO.boxplot(column = ['High_Confidence_Limit '])


# In[68]:


new_HnO = new_HnO.rename(columns = {'High_Confidence_Limit ': 'High_Confidence_Limit'}, inplace = False)


# In[69]:


new_HnO = new_HnO[(new_HnO['High_Confidence_Limit'] >= 10) & (new_HnO['High_Confidence_Limit'] <= 60)]


# In[73]:


new_HnO.boxplot(column = ['High_Confidence_Limit'])


# In[70]:


new_HnO.head()


# In[71]:


new_HnO.shape


# In[78]:


sns.violinplot(x = 'YearEnd' , y = 'Data_Value' , data = new_HnO , split = True)


# In[ ]:




