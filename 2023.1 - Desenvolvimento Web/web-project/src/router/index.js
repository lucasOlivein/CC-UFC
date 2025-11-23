import { createRouter, createWebHistory } from 'vue-router'

import User from '../views/User.vue'
import Admin from '../views/Admin.vue'
import Home from '../views/Main.vue'

import AllAdsVue from '../components/ads/public/AllAds.vue';
import CategoryAdsVue from '../components/ads/public/CategoryAds.vue';
import UserAds from '../components/ads/user/AuthAds.vue';
import AdminAds from '../views/admin/AdminAds.vue'
import AdminUsers from '../views/admin/AdminUsers.vue'
import NotFound from '../erro/NotFound.vue'



import App from '../App.vue'
import { createApp } from 'vue';
import { createPinia } from 'pinia';
import { Auth } from '../stores/user';
import { Ads } from '../stores/ads';
const pinia = createPinia()
const app = createApp()

app.use(pinia)






const router = createRouter({
  history: createWebHistory(),
  routes: [
    {
      path: '/',
      component: Home,
      children: [
        {
          path: '/ads',
          component: AllAdsVue,
          alias: '/',
        },
        {
          path: '/categoria/:categoria',
          component: CategoryAdsVue,
          beforeEnter: (to, from, next) => {
            const ads = Ads()
            if (ads.categoryAdsButton) {
              next();
            } else {
              next('/');
            }
          }
        }
      ]
    },
    {
      path: '/userAds', component: User,

      children: [{
        path: '/userAdsM',
        component: UserAds,
        alias: '/userAds'
      },

      {
        path: '/user/category/:categoria',
        component: UserAds,
        beforeEnter: (to, from, next) => {
          const ads = Ads()
          if (ads.categoryAdsButton) {
            next();
          } else {
            next('/userAds');
          }
        }
      }

      ],
      beforeEnter: (to, from, next) => {
        const auth = Auth()
        if (auth.logged) {
          next();
        } else {
          next('/');
        }
      }


    },

    {
      path: '/admin', component: Admin,
      children: [{
        path: '/admin/ads',
        component: AdminAds,
        alias: '/admin',
        beforeEnter: (to, from, next) => {
          var ads = Ads()
          ads.getAllUsersAds()
          next();
        }
      },
      {
        path: '/admin/category/:categoria',
        component: AdminAds,
        beforeEnter: (to, from, next) => {
          const ads = Ads()
          if (ads.categoryAdsButton) {
            next();
          } else {
            next('/admin');
          }
        }
      },
      {
        path: '/admin/users',
        component: AdminUsers,
        beforeEnter: (to, from, next) => {
          var user = Auth()
          user.getUsers()
          next();
        }
      },

      ],

      beforeEnter: (to, from, next) => {
        const user = Auth()
        if (user.role == 'Admin') {
          next();
        } else {
          next('/');
        }
      }
    },

    {
      path: '/:pathMatch(.*)*', component: NotFound
    }

  ]
})

/* router.beforeEach((to, from, next) => {
  var user = Auth()
  if(user.role == 'Admin')
    to('/admin')
  console.log('Rota de origem:', from);
  console.log('Rota de destino:', to);
  next();
  console.log(auth.logged)
 
}); */

export default router;