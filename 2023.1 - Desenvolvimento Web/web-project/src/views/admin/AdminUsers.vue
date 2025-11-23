<script>
import Headerr from '../../components/header/Header.vue'
import SideMenu from '../../components/menus/SideMenu.vue'
import { Auth } from '../../stores/user';
import UpdateUsersForm from '../../components/form/UpdateUsers.vue'
import { ref } from 'vue';
import AdminNav from '../../components/menus/AdminNav.vue';



export default {
    components: {
        SideMenu,
        UpdateUsersForm,
        AdminNav,
        Headerr,
    },
    data() {
        return {
            response: ref(),
            admin: Auth()
        }
    },


    methods: {
        deleteFail(event, i) {
            this.response = event.message
            console.log(this.response)
            console.log(i)
            this.$refs[`userField${i}`][0].click()
            this.$refs[`failOp${i}`][0].click()

        },
        getUsers() {
            this.admin.getUsers()
        },
        userDeleted(event, i) {
            this.$refs[`userField${i}`][0].click()
            this.admin.users.value[i].deleted = true
        },
        search(event){
            this.admin.filterUser = event
}
    }

}
</script>

<template>
    <SideMenu />
    <div class="container">
        <div class="row">
            <Headerr :home="'/admin'" :users="admin.users.value" @result="search" />
        </div>
        <div class="row">
            <div class="col-9">
                <div class="row" v-for="(user, i) in admin.filterUser" :key="i">
                    <div class="col-12" v-if="user.username != 'webproject'">
                        <div class="container" v-if="!user.deleted">
                            <button class="btn usuario" data-bs-toggle="collapse" :data-bs-target="'#userFields' + i"
                                :ref="'userField' + i">
                                <div class="row">
                                    <h5>{{ user.username }}</h5>
                                </div>
                            </button>


                        </div>
                        <div class="container" v-else>
                            <h5>Usurário removido</h5>
                        </div>

                    </div>
                    <div class="collapse" :id="'userFields' + i">
                        <div class="container">
                            <UpdateUsersForm :userr="user" @userDeleted="userDeleted($event, i)"
                                @deleteFail="deleteFail($event, i)" />
                        </div>
                    </div>
                    <div class="collapse" :id="'failOp' + i">
                        <h5>{{ response }}</h5>
                        <button data-bs-toggle="collapse" :data-bs-target="'#failOp' + i"
                            :ref="'failOp' + i">Concluir</button>
                    </div>
                </div>


            </div>
            <div class="col-3">
                <AdminNav />
            </div>
        </div>
    </div>
</template>

<style scoped>
.usuario {
    width: 80%;
}
</style>