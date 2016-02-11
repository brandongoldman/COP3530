/***********************************
***** Addition of Two Matrices *****
***********************************/

void Addition()
{
	int index_M1 = 0, index_M2 = 0;			// start with initial index -> value = 0
	int tempCol, tempValue;
	
	// keep track of node head for matrix 1 and 2
	currentNode = head;
	currentNode_M2 = head2;
	
	// statement runs when the next element exists in matrix 1
    if(head->ptr != NULL)
    {
        currentNode = head->ptr;
        ++index_M1;
		
        while(currentNode->ptr != NULL)
        {
        	currentNode = currentNode->ptr;
        	++index_M1;
        }
        currentNode = head->ptr;
    }
	
	
    if(head2->ptr != NULL)
    {
        currentNode_M2 = head2->ptr;
        ++index_M2;
        while(currentNode_M2->ptr != NULL)
        {
        	currentNode_M2 = currentNode_M2->ptr;
        	++index_M2;
        }
        currentNode_M2 = head2->ptr;
    }
    
    while(index_M1 > 0 || index_M2 > 0)
    {
        if((currentNode_M2->col < currentNode->col) && index_M2 > 0)
        {
            temp_next_element = currentNode->ptr;
            temp_next_element_M2 = currentNode_M2;
            
			if(currentNode_M2->ptr != NULL)
            {
            	currentNode_M2 = currentNode_M2->ptr;
            }
			
            else
            {
                currentNode_M2 = head2;
            }
			
            currentNode->ptr = temp_next_element_M2;
            temp_next_element_M2->ptr = temp_next_element;
			
            tempCol = temp_next_element_M2->col;
            tempValue = temp_next_element_M2->values;
			
            temp_next_element_M2->col = currentNode->col;
            currentNode->col = tempCol;
			
            temp_next_element_M2->values = currentNode->values;
            currentNode->values = tempValue;
			
            currentNode = currentNode->ptr;
            --index_M2;
        }
		
        else if((currentNode_M2->col < currentNode->col) && index_M2 == 0)
        {
            index_M1 = 0;
        }
		
        else if((currentNode->col < currentNode_M2->col) && index_M1 > 0)
        {
        	if(currentNode->ptr != NULL)
        	{
                currentNode = currentNode->ptr;
            }
            --index_M1;
        }
		
        else if((currentNode->col < currentNode_M2->col) && index_M1 == 0)
        {
        	while(currentNode_M2 != NULL)
        	{
				temp_next_element = currentNode->ptr;
				temp_next_element_M2 = currentNode_M2;
				
				currentNode_M2 = currentNode_M2->ptr;		// ptr points to next element
				currentNode->ptr = temp_next_element_M2;
				
				temp_next_element_M2->ptr = temp_next_element;
				--index_M2;
        	}
        }
		
        else if((currentNode->col == currentNode_M2->col) && index_M1 > 0 && index_M2 > 0)
        {
            currentNode->values = currentNode->values + currentNode_M2->values;
            if(currentNode->ptr != NULL)
        	{
                currentNode = currentNode->ptr;
            }
            if(currentNode_M2->ptr != NULL)
            {
            	currentNode_M2 = currentNode_M2->ptr;
            }
            --index_M1;
            --index_M2;
        }
    }
} 
