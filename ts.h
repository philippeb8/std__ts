/**

    This file is part of Thread-Safe (TS) STL Containers.

    TS STL Containers is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    TS STL Containers is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with TS STL Containers. If not, see <https://www.gnu.org/licenses/>.
    
    @Author: Phil Bouchard <phil@fornux.com>
    @Date: May 28, 2023

 */

#pragma once

#include <mutex>

#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>

namespace std
{
    
namespace ts
{
    
template <template <typename...> class C, typename... Params>
    class container : public C<Params...>
    {
    public:
        container() = default;
        
        container(const container& other)
        {
            std::lock_guard<std::mutex> lock(mutex_, other.mutex_);
            
            C<Params...>::operator=(other);
        }
        
        container& operator=(const container& other)
        {
            if (this == &other)
                return *this;
            
            std::lock_guard<std::mutex> lock(mutex_, other.mutex_);
            
            C<Params...>::operator=(other);
            
            return *this;
        }
        
        container(container&& other) noexcept
            : C<Params...>(std::move(other))
        {
        }
        
        container& operator=(container&& other) noexcept
        {
            if (this == &other)
                return *this;
            
            std::lock_guard<std::mutex> lock(mutex_, other.mutex_);
            
            C<Params...>::operator=(std::move(other));
            
            return *this;
        }
        
        template <typename... Args>
            auto empty()
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::empty();
            }

        template <typename... Args>
            auto insert(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::insert(std::forward<Args>(args)...);
            }

        template <typename... Args>
            auto emplace(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::emplace(std::forward<Args>(args)...);
            }

        template <typename... Args>
            auto emplace_hint(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::emplace_hint(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto push_back(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::push_back(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto push_front(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::push_front(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto emplace_back(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::emplace_back(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto emplace_front(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::emplace_front(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto resize(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::resize(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto clear(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::clear(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto erase(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::erase(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto pop_back(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::pop_back(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto pop_front(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::pop_front(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto remove(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::remove(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto remove_if(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::remove_if(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto unique(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::unique(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto merge(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::merge(std::forward<Args>(args)...);
            }
            
        template <typename... Args>
            auto splice(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::splice(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto swap(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::swap(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto assign(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::assign(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto pop_heap(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::pop_heap(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto push_heap(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::push_heap(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto make_heap(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::make_heap(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto sort(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::sort(std::forward<Args>(args)...);
            }
        
        template <typename... Args>
            auto reverse(Args &&... args)
            {
                std::lock_guard<std::mutex> lock(mutex_);
                
                return C<Params...>::reverse(std::forward<Args>(args)...);
            }
        
    private:
        std::mutex mutex_;
    };
    
template <typename... Params>
    using vector = container<std::vector, Params...>;
template <typename... Params>
    using deque = container<std::deque, Params...>;
template <typename... Params>
    using list = container<std::list, Params...>;
template <typename... Params>
    using forward_list = container<std::forward_list, Params...>;
template <typename... Params>
    using set = container<std::set, Params...>;
template <typename... Params>
    using multiset = container<std::multiset, Params...>;
template <typename... Params>
    using map = container<std::map, Params...>;
template <typename... Params>
    using multimap = container<std::multimap, Params...>;
template <typename... Params>
    using unordered_set = container<std::unordered_set, Params...>;
template <typename... Params>
    using unordered_multiset = container<std::unordered_multiset, Params...>;
template <typename... Params>
    using unordered_map = container<std::unordered_map, Params...>;
template <typename... Params>
    using unordered_multimap = container<std::unordered_multimap, Params...>;
template <typename... Params>
    using stack = container<std::stack, Params...>;
template <typename... Params>
    using queue = container<std::queue, Params...>;
template <typename... Params>
    using priority_queue = container<std::priority_queue, Params...>;
}

}
