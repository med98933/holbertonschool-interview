import requests

def count_words(subreddit, word_list, after=None, counts=None):
    if counts is None:
        counts = {}
    
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-agent': 'Mozilla/5.0'}
    params = {'limit': 100}
    
    if after:
        params['after'] = after
        
    response = requests.get(url, headers=headers, params=params)
    
    if response.status_code == 200:
        data = response.json()['data']
        after = data['after']
        posts = data['children']
        
        for post in posts:
            title = post['data']['title'].lower()
            for word in word_list:
                if word.lower() in title:
                    word = word.lower()
                    if word in counts:
                        counts[word] += 1
                    else:
                        counts[word] = 1
        
        if after:
            count_words(subreddit, word_list, after=after, counts=counts)
        else:
            sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
            for word, count in sorted_counts:
                print(word, count)
    else:
        print(f"Error: {response.status_code}")
