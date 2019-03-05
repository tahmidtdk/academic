
grammar experiment;

Sentence : Noun_Phrase | Verb_Phrase;

Noun_Phrase : Name | Complex_Noun | Complex_Noun Prepositional_Phrase;

Prepositional_Phrase : Preposition Complex_Noun;

Complex_Noun: Article Noun |  Article Adjective Noun;

Verb_Phrase: Verb | Adverb Verb_Phrase | Verb Noun_Phrase;

Article: a | the | an;

Noun: boy | girl | flower | cake | book | library;

Name : Alice | Bob | Carol;


Adjective : tall | shy | green;

Verb: likes | eats | touches | sees
;

Adverb: quickly | soflty
;

Preposition: with | under | at;