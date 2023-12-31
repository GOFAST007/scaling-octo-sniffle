#include "item_stack.h"

#include <algorithm>
#include <utility>

#include "item.h"
#include "output.h"
#include "units.h"
#include "debug.h"

size_t item_stack::size() const
{
    return items->size();
}

bool item_stack::empty() const
{
    return items->empty();
}

std::vector<detached_ptr<item>> item_stack::clear()
{
    return items->clear();
}

item_stack::iterator item_stack::begin()
{
    return items->begin();
}

item_stack::iterator item_stack::end()
{
    return items->end();
}

item_stack::const_iterator item_stack::begin() const
{
    return items->cbegin();
}

item_stack::const_iterator item_stack::end() const
{
    return items->cend();
}

item_stack::reverse_iterator item_stack::rbegin()
{
    return items->rbegin();
}

item_stack::reverse_iterator item_stack::rend()
{
    return items->rend();
}

item_stack::const_reverse_iterator item_stack::rbegin() const
{
    return items->crbegin();
}

item_stack::const_reverse_iterator item_stack::rend() const
{
    return items->crend();
}

item &item_stack::only_item()
{
    if( empty() ) {
        debugmsg( "Missing item at target location" );
        return null_item_reference();
    } else if( size() > 1 ) {
        debugmsg( "More than one item at target location: %s", enumerate_as_string( begin(),
        end(), []( const item * const & it ) {
            return it->typeId();
        } ) );
        return null_item_reference();
    }
    return **items->begin();
}

units::volume item_stack::stored_volume() const
{
    units::volume ret = 0_ml;
    for( const item * const &it : *items ) {
        ret += it->volume();
    }
    return ret;
}

int item_stack::amount_can_fit( const item &it ) const
{
    // Without stacking charges, would we violate the count limit?
    const bool violates_count = size() >= static_cast<size_t>( count_limit() );
    const item *here = it.count_by_charges() ? stacks_with( it ) : nullptr;

    if( violates_count && !here ) {
        return 0;
    }
    // Call max because a tile may have been overfilled to begin with (e.g. #14115)
    const int ret = std::max( 0, it.charges_per_volume( free_volume() ) );
    return it.count_by_charges() ? std::min( ret, it.charges ) : ret;
}

item *item_stack::stacks_with( const item &it )
{
    for( item *&here : *items ) {
        if( here->stacks_with( it ) ) {
            return here;
        }
    }
    return nullptr;
}

const item *item_stack::stacks_with( const item &it ) const
{
    for( const item * const &here : *items ) {
        if( here->stacks_with( it ) ) {
            return here;
        }
    }
    return nullptr;
}

units::volume item_stack::free_volume() const
{
    return max_volume() - stored_volume();
}

void item_stack::move_all_to( item_stack *destination )
{
    for( detached_ptr<item> &it : items->clear() ) {
        destination->insert( std::move( it ) );
    }
}

void item_stack::remove_top_items_with( std::function < detached_ptr<item>
                                        ( detached_ptr<item> && ) > cb )
{
    items->remove_with( std::move( cb ) );
}
