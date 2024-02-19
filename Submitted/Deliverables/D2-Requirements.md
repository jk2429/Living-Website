# Requirements
## 1. Positioning
> a. Problem Statement  
>> i. The problem of websites being difficult and time consuming to navigate as well as hard to maintain affects everyday people.  This costs people time and money when doing something they frequently take part in every day

> b. Product Position Statement  
>> i. For everyone who browses the web, the Living Website concept is an eCommerce website that changes location of frequently visited links for ease of access.  Unlike other websites, our website adapts to what its users want to access

> a. Value Proposition and Customer Segment  
>> i. The Living-Website is an online shopping website that allows online shoppers to more easily navigate the site, showing them the pages that they want to see first and allowing easy navigation to every page  
## 2. Stakeholders  
> a. List of all stakeholders  
>> i. Online shoppers - They will benefit from the product as well as help increase the efficiency of the website.  
>> ii. Web programmers - The simple and efficient layout of the site not only makes it easier to navigate, but also allows for more efficient maintenance and additions.  
>> iii. Application developers - In charge of keeping the program up to date that will check the database and update the website as needed.  
>> iv. Database developers - Keep the database up to date with the correct entities and maintain any issues within the database.  
>> v. Companies with online stores - They can implement this concept to improve their user experience and how their users shop.  
## 3. Functional requirements  
> a. Storage system to hold each page  
> b. Capability to record what pages are accessed  
> c. Capability to connect both ways to storage system  
> d. Capability to change homepage layout automatically  
> e. Ability to update webpage and make changes live  
> f. SCP pages to browse accessible from the home page  
> g. Live website accessible through HTTPS on any web browser  
## 4. Non-functional requirements
> a. Functional Suitability - SCP pages, make aesthetically pleasing and complete pages showing information about SCPs.  
> b. Functional Suitability - “Buy” option, allow users to add items to the cart and “buy” them.  
> c. Reliability - Site backup, store an unmodified version of the site in case of bugs or errors.  
> d. Performance Efficiency - SQL database, use a database to store site information to improve performance.  
> e. Usability - Navigation bar, allow users to browse different types of SCP’s by selecting from a navigation bar.  
> f. Usability - Homepage recommended section, show the most accessed SCP pages from the homepage.  
> g. Security - Transparency, include an about section which explains how the site functions, how to access any page on the site, and how the site uses user data.  
> h. Maintainability - Easy expansion, Simplify the process of adding additional pages to the site for easy scalability.  
> i. Portability - All developers are able to modify the webpage remotely from their own devices.  
## 5. MVP
> Home Page:  
>> Navigator bar that will change according to usage  
>>> -Classes: Keter,Safe, Ecuclid, etc.  
>>> -Numbers: 1-99, 1000-1099 (1000 per page)  
>>> -Top Entities: Most popular entities  
>>> -Shopping Cart  
>>> -Search Bar?  
>>> -About  
> One SCP entity for sale  

## 6. Use Cases  
![CS386D2UseCaseDiagram](https://github.com/swBodenhemier/Living-Website/assets/148917317/275c8e7d-fac5-4341-99a3-ceff3943845c)

> a. Use Case 1: User accesses a page  
>> Actor: User  
>> Trigger: The user decides to access a page  
>> Pre-conditions: The user is on a navigation page  
>> Post-condition: User gains access to a page  
>> Success Scenario:  
>>> 1. The user chooses a page to access  
>>> 2. The system locates the page contents  
>>> 3. The system notes that the page was accessed  
>>> 4. The page is loaded  
>>> 5. The user is directed to the page  

> b. Use Case 2: Update the HTML website  
>> Actor: Application developer  
>> Trigger:Weekly timer or user input update  
>> Pre-conditions: Access to database entities and HTML file  
>> Post-conditions: Updated HTML file  
>> Success Scenario:  
>>> 1. Checks database for any change  
>>> 2. Compare the database to the current organization of the website  
>>> 3. Update the HTML file to structure it

>> Alternate Scenario:  
>>> 1. No change in database entities so there will be no change in the website  

> c. Use Case 3: Adding item to store  
>> Actor: Web Programmer  
>> Trigger: a new page is added to the website  
>> Pre-conditions: Programmer designs and creates item page  
>> Post-conditions: Item is added to the website for user access  
>> Success Scenario:
>>> 1. Item exists
>>> 2. Data on times the item is clicked is properly recorded
>>> 3. Is properly seen in the database

>> Alternate Scenario:
>>> 1. New item does not exist
>>> 2. Item is not properly added to database
>>> 3. Data on the times the item is clicked on does not update  

> d. Use Case 4: user searches for a SCP  
>> Actor: End User  
>> Trigger: user wants to find an SCP with specific information about it  
>> Pre-conditions: none  
>> Post-conditions: page with appropriate SCP is displayed  
>> Success Scenario:  
>>> 1. User provides accurate information about an SCP  
>>> 2. The database is queried   
>>> 3 The page with the appropriate SCP is displayed  

>> Alternate Scenario:  
>>> 1. User provides NULL or data not relating to any SCP  
>>> 2. Database is queried  
>>> 3. An error is displayed  

## 7. User Stories  
> 1. As a user I want access to an efficient navigation system so I can shop/browse easier.  
>> Priority: 89/89  
>> Estimate: Whole project lifetime  
>> Constraints: Clutter/hard readability, less is more,   
>>Note: This type of thinking should be a priority for everything related to this project.  
> 2. As a supplier I want an easy way to add items to the shop so I can promote more of my shop.  
>> Priority: 15/89  
>> Estimate: 2 Weeks  
>> Constraints: Access to upload new entities, upload another webpage to add an item  
>3. As a shopper, I want to see the most popular items first so I can know what is a good product to purchase.  
>> Priority: 27/89  
>> Estimate: 3 week  
>> Constraints: Unknown amount of store sections, organization of website  
>4. As a user, I want to know how to access a specific page so I can avoid difficult navigation.  
>> Priority: 48/89  
>> Estimate: Whole Project Lifetime  
>> Constraints: Understandable navigation system, about page to explain the layout for users who are struggling with navigation  
>> Note: This type of thinking should be a priority for everything related to this project.  
>5. As a user, I want a way to find navigation tabs and items on the website, so I can find what I’m looking for efficiently.  
>> Priority: 21/89  
>> Estimate: 3 weeks    
>> Constraints: Search for entities, make sure it is not too narrow of a search with a generic search item, genre(classes, number, etc).  
> 6. As a website owner, I want the ability to know how long users spend looking at an item, so that I can know what kinds of products interest users the most.  
>> Priority: 5/89  
>> Estimate: 1 month  
>> Constraints: Accounting for active time spent on the website, priority over other ways of collecting data.  
> 7. As a developer I want an easy way to upload new items so I can track and store new entities.  
>> Priority:18/89  
>> Estimate: 2 weeks  
>> Constraints: Access to a server, creating new pages that are templated correctly  
> 8. As a web programmer, I want an easy way to add new web pages so that developing new pages is faster.  
>> Priority: 21/89  
>> Estimate: 1 week  
>> Constraints: Less is more, uniform style for templating, aesthetically pleasing  
