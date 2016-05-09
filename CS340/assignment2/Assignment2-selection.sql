#1 Find all films with maximum length and minimum rental duration (compared to all other films). 
#In other words let L be the maximum film length, and let R be the minimum rental duration in the table film. You need to find all films with length L and rental duration R.
#You just need to return attribute film id for this query. 

SELECT film_id 
FROM film 
WHERE length=(SELECT MAX(length) FROM film) 
AND rental_duration=(SELECT MAX(rental_duration) FROM film);

#2 We want to find out how many of each category of film ED CHASE has started in so return a table with category.name and the count
#of the number of films that ED was in which were in that category order by the category name ascending (Your query should return every category even if ED has been in no films in that category).

SELECT name, SUM(CASE WHEN actor.first_name="ED" 
					AND actor.last_name="CHASE" 
                    THEN 1 ELSE 0 END) as ed_is_in
FROM category 
INNER JOIN film_category
	ON category.category_id=film_category.category_id
INNER JOIN film
	ON film.film_id=film_category.film_id
INNER JOIN film_actor
	ON film_actor.film_id=film.film_id
INNER JOIN actor
	ON actor.actor_id=film_actor.actor_id
GROUP BY category.name
ORDER BY ed_is_in DESC;

#3 Find the first name, last name and total combined film length of Sci-Fi films for every actor
#That is the result should list the names of all of the actors(even if an actor has not been in any Sci-Fi films)and the total length of Sci-Fi films they have been in.

SELECT first_name, last_name, 
SUM(CASE WHEN category.category_id=(SELECT category_id 
									FROM category 
                                    WHERE name="Sci-Fi") 
	THEN film.length ELSE 0 END) as sci_fi_length
FROM actor
INNER JOIN film_actor
	ON film_actor.actor_id=actor.actor_id
INNER JOIN film
	ON film.film_id=film_actor.film_id
INNER JOIN film_category
	ON film_category.film_id=film.film_id
INNER JOIN category
	ON category.category_id=film_category.category_id
GROUP BY actor.actor_id;


#4 Find the first name and last name of all actors who have never been in a Sci-Fi film
SELECT first_name, last_name
FROM actor
WHERE actor.actor_id NOT IN (
SELECT actor.actor_id
FROM actor
INNER JOIN film_actor
	ON film_actor.actor_id=actor.actor_id
INNER JOIN film
	ON film.film_id=film_actor.film_id
INNER JOIN film_category
	ON film_category.film_id=film.film_id
INNER JOIN category
	ON category.category_id=film_category.category_id
WHERE film_category.category_id=(SELECT category_id
								FROM category
								WHERE name="Sci-Fi")
)
GROUP BY actor.actor_id;

#5 Find the film title of all films which feature both KIRSTEN PALTROW and WARREN NOLTE
#Order the results by title, descending (use ORDER BY title DESC at the end of the query)
#Warning, this is a tricky one and while the syntax is all things you know, you have to think oustide
#the box a bit to figure out how to get a table that shows pairs of actors in movies

SELECT film.title
FROM film
INNER JOIN film_actor
	ON film_actor.film_id=film.film_id 
LEFT JOIN actor as kirsten
	ON film_actor.actor_id=kirsten.actor_id AND kirsten.actor_id=(SELECT actor.actor_id
							FROM actor
                            WHERE actor.first_name="Kirsten" AND actor.last_name="Paltrow")
LEFT JOIN actor as warren
	ON film_actor.actor_id=warren.actor_id AND warren.actor_id=(SELECT actor.actor_id
							FROM actor
                            WHERE actor.first_name="Warren" AND actor.last_name="Nolte")
WHERE 	
	(kirsten.actor_id=(	SELECT actor.actor_id
						FROM actor
						WHERE actor.first_name="Kirsten" AND actor.last_name="Paltrow"))
	OR 
	(warren.actor_id=(	SELECT actor.actor_id
						FROM actor
						WHERE actor.first_name="Warren" AND actor.last_name="Nolte"))
GROUP BY film.title
HAVING COUNT(title) > 1

