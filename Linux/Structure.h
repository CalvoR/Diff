#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED


struct difference   {

	char diffType ;

	int startLineSrc ;
	int endLineSrc ;
	int startLineDest ;
	int endLineDest ;

	t_difference* nextDiff;

} t_difference;

#endif // STRUCTURE_H_INCLUDED
