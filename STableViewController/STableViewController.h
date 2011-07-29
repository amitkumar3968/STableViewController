//
//  STableViewController.h
//  STableViewController
//
//  Created by Shiki on 7/27/11.
//

#import <UIKit/UIKit.h>


@interface STableViewController : UIViewController <UITableViewDelegate, UITableViewDataSource> {

@protected
  
  BOOL isDragging;
  BOOL isRefreshing;
  BOOL isLoadingMore;
  BOOL noMoreItemToLoad;
  
  // had to store this because the headerView's frame seems to be changed somewhere during scrolling
  // and I couldn't figure out why >.<
  CGRect headerViewFrame;
}

// The view used for "pull to refresh"
@property (nonatomic, retain) UIView *headerView;

// The view used for "load more"
@property (nonatomic, retain) UIView *footerView;

@property (nonatomic, retain) UITableView *tableView;
@property (readonly) BOOL isDragging;
@property (readonly) BOOL isRefreshing;
@property (readonly) BOOL isLoadingMore;
@property (readonly) BOOL noMoreItemsToLoad;

#pragma mark - Pull to Refresh

// The minimum height that the user should drag down in order to trigger a "refresh" when
// dragging ends. 
- (CGFloat) headerRefreshHeight;

// Will be called if the user drags down which will show the header view. Override this to
// update the header view (e.g. change the label to "Pull down to refresh").
- (void) willShowHeaderView:(UIScrollView *)scrollView;

// If the user is dragging, will be called on every scroll event that the headerView is shown. 
// The value of willRefreshOnRelease will be YES if the user scrolled down enough to trigger a 
// "refresh" when the user releases the drag.
- (void) headerViewDidScroll:(BOOL)willRefreshOnRelease scrollView:(UIScrollView *)scrollView;

// By default, will permanently show the headerView by setting the tableView's contentInset.
- (void) pinHeaderView;

// Reverse of pinHeaderView. 
- (void) unpinHeaderView;

// Called when the user stops dragging and, if the conditions are met, will trigger a refresh.
- (void) willBeginRefresh;

// Override to perform fetching of data.
- (void) refresh;

// Call to signal that refresh has completed. This will then hide the headerView.
- (void) refreshCompleted;

#pragma mark - Load More

- (CGFloat) footerLoadMoreHeight;

// Override to perform fetching of next page of data
- (BOOL) loadMore;

//
- (void) willBeginLoadingMore;

// 
- (void) loadMoreCompleted:(BOOL)noMoreItemsToLoad;

//
- (void) hideFooterView;

@end
